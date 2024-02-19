#include <stdio.h>
#include <stdlib.h>
#include "q5.h"


void print_list (CellPtr list){
	CellPtr current=list;
	while (current!=NULL){
		printf("%d\n",current->contents);
		current=current->next;
	}
}
 
void print_rev(CellPtr list){
	CellPtr current=list;
	while (current->next!=NULL){
		current=current->next;
	}
	
		while (current!=NULL)
		{
			printf("%d\n",current->contents);
			current=current->prev;
		}
		
}
		
CellPtr insert_first (CellPtr list, int input){
	CellPtr new_cell=(CellPtr)malloc(sizeof(Cell));
	new_cell->contents=input;
	new_cell->next=list;
	new_cell->prev=NULL;
	if (list!=NULL){
		list->prev=new_cell;
	}
	
	return new_cell;}
	
CellPtr remove_first (CellPtr list, int *output){
	*output=list->contents;
	CellPtr new_list=list->next;
	free(list);
	return new_list;}

 