#include <stdlib.h>
#include <stdio.h>

void update(int *a , int *b);
int main();

void update(int *a,int *b){
	int temp1;
	int temp2;
	temp1=*a;
	temp2=*b;
	*a=temp1+temp2;
	*b=temp1-temp2;
	printf("%d\n",*a);
	printf("%d\n",*b);
			}
int main(){
	int a=10;
	int b=23;
	update(&a,&b);
	
	}
