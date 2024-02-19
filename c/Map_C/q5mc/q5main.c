#include <stdio.h>
#include "q5.h"

int main()
{
	CellPtr list=NULL;
	list=insert_first(list,1);
	list=insert_first(list,2);
	list=insert_first(list,3);
	printf("Forward");
	print_list(list);
	printf("Backwards");
	print_rev(list);
	int output;
	list=remove_first(list, &output);
	printf("Forward");
	print_list(list);}