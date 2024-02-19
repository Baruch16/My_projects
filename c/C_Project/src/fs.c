#include "fs.h"
#include "disk.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define FS_MAGIC           0xf0f03410
#define INODES_PER_BLOCK   128
#define POINTERS_PER_INODE 5
#define POINTERS_PER_BLOCK 1024

static int * bitmap=NULL;
static int SIZE = 0;

//function to free the memory allocated to the bit map
void free_bitmap()
{

	free(bitmap);
}
	
//function to find an empty block and retrun it
int find_empty_block()
{
	for (int i = 0; i < SIZE; ++i){
		if (bitmap[i] == 0){
			bitmap[i] = 1;
			return calculate_block_index(i);
		}
	}
	return -1;
}

// function to free a block by changing the bit map value from 1 to 0
void free_block(int data_block_index)
{
	int i = calculate_bit_map_index(data_block_index);
	bitmap[i] = 0;
}

//function to calculate the index of the block in relation to all the inodes
int calculate_block_index(int index)
{
	union fs_block block;

	disk_read(0,block.data);

	return (block.super.ninodeblocks + index +1);
}

//function to calculate the index of the bit map in relation to all the inodes
int calculate_bit_map_index(int index)
{
	union fs_block block;

	disk_read(0,block.data);

	return (index - block.super.ninodeblocks -1);
}

//function to find an empty node
int find_empty_inode()
{
	union fs_block block;

	disk_read(0,block.data);
	
	int size = block.super.ninodeblocks;
	
	for (int i = 1; i <= size; ++i)
	{
		disk_read(i,block.data);
		
		for(int j = 0; j < INODES_PER_BLOCK; ++j)
			if (!block.inode[j].isvalid)
				return (((i-1) * INODES_PER_BLOCK) + j); 
		
	}
	
	return -1;
}
//function to load an inode 
struct fs_inode inode_load(int inumber)
{
	int n = (inumber/INODES_PER_BLOCK) +1, j = inumber%INODES_PER_BLOCK;
	
	union fs_block block;
	disk_read(n,block.data);
	
	return block.inode[j];
}

//function to save an inode
void inode_save(int inumber, struct fs_inode inode)
{
	int n = (inumber/INODES_PER_BLOCK) +1, j = inumber%INODES_PER_BLOCK;
	
	union fs_block block;
	disk_read(n,block.data);
	
	block.inode[j] = inode;
	
	disk_write(n,block.data);
}

//function to free an inode
int free_inode(int inumber)
{	
	struct fs_inode inode = inode_load(inumber);
	
	int i = 0;
	for (; i < inode.size && i < POINTERS_PER_INODE; ++i)
		free_block(inode.direct[i]);
	
	if(inode.indirect)
	{
		union fs_block in_block;
		disk_write(inode.indirect, in_block.data);
		
		for (; i < inode.size; ++i)
			free_block(in_block.pointers[i - POINTERS_PER_INODE]);
	}
	
	inode.isvalid = 0;
	inode.indirect = 0;
	
	inode_save(inumber, inode);	
	
	return 1;
}



//function to create an indoe
void create_inode(int inumber)
{
	struct fs_inode inode;
	
	inode.isvalid = 1;
	inode.size = 0;
	inode.indirect = 0;
	
	
	for (int i = 0; i < POINTERS_PER_INODE; ++i)
		inode.direct[i] = 0;
	
	inode_save(inumber, inode);
}
//finds in an inode a specific block index in the direct/indirect
int find_block(int inumber,int block_number,char command)
{
	struct fs_inode inode=inode_load(inumber);
	
	if(block_number<POINTERS_PER_INODE)
	{
		if(inode.direct[block_number])
			return inode.direct[block_number];
	
		else if (command=='w')
		{
			inode.direct[block_number]=find_empty_block();
			if (inode.direct[block_number]==-1)
				return -1;
			inode_save(inumber,inode);
			return inode.direct[block_number];
			}
		else
			return -1;
	}
	union fs_block block;
	if (!inode.indirect){
		if(command=='w'){
			inode.indirect=find_empty_block();
			if(inode.indirect==-1)
				return -1;
			
			disk_read(inode.indirect,block.data);
			for(int temp=0;temp<POINTERS_PER_BLOCK;++temp)
				block.pointers[temp]=0;
			disk_write(inode.indirect,block.data);
			}
		return -1;
		}
	int indirect=inode.indirect;
	block_number-=POINTERS_PER_INODE;
	
	do{
		disk_read(indirect,block.data);
		if(block_number<POINTERS_PER_BLOCK){
			if(block.pointers[block_number])
				return block.pointers[block_number];}
		else if (command=='w'){
			block.pointers[block_number]=find_empty_block();
			if(block.pointers[block_number]==-1)
				return -1;
			inode_save(inumber,inode);
			disk_write(indirect,block.data);
			return block.pointers[block_number];
		}
		else return -1;
		
		indirect=block.pointers[POINTERS_PER_BLOCK-1];
	}
	
	while(!indirect);
		return -1;
}


//function to format the fs
int fs_format()
{	union fs_block block;
	disk_read(0,block.data);
	if(block.super.magic == FS_MAGIC)
		return 0;
	
	int size=disk_size();
	block.super.magic=FS_MAGIC;
	block.super.nblocks=size;
	block.super.ninodeblocks=size/10 +1;
	block.super.ninodes=INODES_PER_BLOCK*(size/10+1);
	disk_write(0,block.data);
		
	for (int i = 1; i <= size/10 +1; ++i)
	{
		disk_read(i,block.data);
		
		for(int j = 0; j < INODES_PER_BLOCK; ++j)
			block.inode[j].isvalid = 0;
	}
			
	return 1;
		
}
//function to debug and write all the info about the superblock and the inodes
void fs_debug()
{
	union fs_block block;

	disk_read(0,block.data);

	printf("superblock:\n");
	printf("    %d blocks\n",block.super.nblocks);
	printf("    %d inode blocks\n",block.super.ninodeblocks);
	printf("    %d inodes\n",block.super.ninodes);
	
	union fs_block indirect_block;
	int ninodeblocks = block.super.ninodeblocks;
	for (int i=1;i<=ninodeblocks;++i){
		disk_read(i,block.data);
		for(int j=0;j<INODES_PER_BLOCK;++j){
			if(block.inode[j].isvalid){
				printf("inode: %d,%d. the size of the inode is:%d bytes\n",i,j,block.inode[j].size);
				printf("\tdirect blocks: ");
				for (int c=0;c<POINTERS_PER_INODE;++c)
					printf("%d , ",block.inode[j].direct[c]);
				printf("\tindirect blocks: %d\n",block.inode[j].indirect);
				if (block.inode[j].indirect){
					printf("\tindirect data blocks: ");
					disk_read(block.inode[j].indirect ,indirect_block.data);
					for(int c=0;c<POINTERS_PER_BLOCK;++c){
						if(indirect_block.pointers[c])
							printf("%d ", indirect_block.pointers[c]);
						}
						printf("\n");
				}
			}
		}
	}
	
}
//function to create the bit map and check if the files are ready to use
int fs_mount()
{	if(bitmap !=NULL)
		return 0;
	union fs_block block;
	disk_read(0,block.data);
	int size =block.super.nblocks;
	SIZE = size;
	bitmap=(int*)calloc(size,sizeof(int));
	for(int i=1;i<=block.super.ninodeblocks;++i){
		disk_read(i,block.data);
		for(int j; j<INODES_PER_BLOCK;++j){
			if(block.inode[j].isvalid){
			int i=0;
			if((block.inode[j].size/ DISK_BLOCK_SIZE)+1<6){
				while(i<block.inode[j].size/ DISK_BLOCK_SIZE)
					bitmap[block.inode[j].direct[i++]]=1;
			}
			else {
				while(i< POINTERS_PER_INODE)
					bitmap[block.inode[j].direct[i++]]=1;
				disk_read(block.inode[j].indirect,block.data);
				while(i<block.inode[j].size/ DISK_BLOCK_SIZE){
					bitmap[block.pointers[i-POINTERS_PER_INODE]]=1;
					i++;
				}
			}
			}
		}
	}
	return 1;
}
//function to create an inode 
int fs_create()
{	
	int inode=find_empty_inode();
	if (inode==-1)
		return -1;
	create_inode(inode);
	return inode;		
			
				
	

}
//function to delete an inode
int fs_delete( int inumber )
{
	if (inumber <0 || inumber>  INODES_PER_BLOCK*disk_size()){
		return 0;
		}
	return free_inode(inumber);
	
}
//function to get the size of the inode
int fs_getsize( int inumber )
{	
	struct fs_inode inode=inode_load(inumber);
	if (inode.isvalid)
		return inode.size;
	return 0;
}
//function to read whatever is written inside by posting it into a file
int fs_read( int inumber, char *data, int length, int offset )
{	
	struct fs_inode inode=inode_load(inumber);
	if(!inode.isvalid){
		printf("Error: the inode is not valid");
		return 0;
	}
	int read_bytes=0;
	int endpoint_ptr = (inode.size>offset+length) ? offset+length : inode.size;
	
	while (offset< endpoint_ptr){
		int block_number=offset/DISK_BLOCK_SIZE;
		int data_index=offset%DISK_BLOCK_SIZE;
		int block_index;
		block_index=find_block(inumber,block_number,'r');
		if (block_index==-1)
			return read_bytes;
			
		union fs_block block;
		disk_read(block_index,block.data);
		int temp=data_index;
		for(;temp<DISK_BLOCK_SIZE && temp<(endpoint_ptr-offset);++temp)
			*data++=block.data[temp];
		offset+=(temp-data_index);
		read_bytes+=(temp-data_index);
		}
	return read_bytes;
}
//function to write into an inode whatever is in the file
int fs_write( int inumber, const char *data, int length, int offset )
{	
	struct fs_inode inode=inode_load(inumber);
	if(!inode.isvalid){
		printf("Error: the inode is not valid");
		return 0;
	}
	if(!offset){
		inode.size=0;
		inode_save(inumber,inode);
	}
	int written_bytes=0;
	int endpoint_ptr = offset+length;
	int left=length;
	while (offset< endpoint_ptr){
		int block_number=offset/DISK_BLOCK_SIZE;
		int data_index=offset%DISK_BLOCK_SIZE;
		int block_index;
		block_index=find_block(inumber,block_number,'w');
		if (block_index==-1){
		
			inode=inode_load(inumber);
			inode.size+=written_bytes;
			inode_save(inumber,inode);
			return written_bytes;
		}
				
		union fs_block block;
		disk_read(block_index,block.data);
		int temp=data_index;
		for(;temp<DISK_BLOCK_SIZE && temp<left;++temp)
			block.data[temp]= *data++;
			
		offset+=(temp-data_index);
		written_bytes+=(temp-data_index);
		left-=(temp=data_index);
		
		disk_write(block_index,block.data);
	}
	//Load the updated inode and save the updates//
	inode=inode_load(inumber);
	inode.size += written_bytes;
	inode_save(inumber,inode);
	return written_bytes;
	
		
			
}
