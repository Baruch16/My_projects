#ifndef FS_H
#define FS_H
#define FS_MAGIC           0xf0f03410
#define INODES_PER_BLOCK   128
#define POINTERS_PER_INODE 5
#define POINTERS_PER_BLOCK 1024
#define DISK_BLOCK_SIZE 4096
#include <stdlib.h>


struct fs_superblock {
	int magic;
	int nblocks;
	int ninodeblocks;
	int ninodes;
};

struct fs_inode {
	int isvalid;
	int size;
	int direct[POINTERS_PER_INODE];
	int indirect;
};

union fs_block {
	struct fs_superblock super;
	struct fs_inode inode[INODES_PER_BLOCK];
	int pointers[POINTERS_PER_BLOCK];
	char data[DISK_BLOCK_SIZE];
};
void fs_debug();
int  fs_format();
int  fs_mount();
void free_bitmap();
int  fs_create();
int  fs_delete( int inumber );
int  fs_getsize();

int  fs_read( int inumber, char *data, int length, int offset );
int  fs_write( int inumber, const char *data, int length, int offset );

/* bit map */
int find_empty_block();
void free_block(int data_block_index);
int calculate_block_index(int index);
int calculate_bit_map_index(int index);

/* inodes */
int find_empty_inode();

/* inode */
struct fs_inode inode_load(int inumber);
void inode_save(int inumber, struct fs_inode inode);
void create_inode(int inode);
int free_inode(int inode);
void link_direct(int * ptr);
int increse(int inode, int size);
int find_block(int inumber,int block_number,char command);

#endif
