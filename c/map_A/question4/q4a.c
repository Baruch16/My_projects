#include <stdio.h>

void swap(int **a,int **b);

void swap(int **a,int **b){
	int *tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;}

void print_array(int *array, int size){

	int arr_size=size;
	for(int i=0; i<arr_size;++i)
		printf("%d.",*(array+i));
	printf("\n");
	}
int main(){
	int arr_a[]={5,3,2,6};
	int arr_b[]={6,9,2,5,7,3};
	int* a=arr_a;
	int* b=arr_b;
	swap(&a,&b);
	print_array(a,6);
	print_array(b,4);
	}
