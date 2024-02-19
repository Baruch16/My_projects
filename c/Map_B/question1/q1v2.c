# include <stdio.h>

void  print_arrays(int arr[][5]);
void check_max(int arr[][5]);
void sum_odd(int arr[][5]);

int create_2d_array(){
	int (num[2][5]);
	for (int i=0;i<2;i++){
		for (int j=0;j<5;j++){
			printf("Enter the desired number");
			int n;
			scanf("%d",&n);
			num[i][j]=n;}
			}
	print_arrays(num);
	check_max(num);	
	sum_odd(num);
}

void print_arrays(int arr[][5])
{
	for (int i = 0; i <2; ++i)
	{
		for (int j = 0; j <5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void check_max(int arr[][5]){
	for (int i = 0; i <2; ++i)
	{	int a=0;
		for (int j = 0; j <5; j++){
		 if (a<arr[i][j])
		 	a=arr[i][j];
		 }
		 printf("%d\n",a);
	}

}
void sum_odd(int arr[][5]){
	int a=0;
	for (int i = 0; i <2; ++i)
	{
		for (int j = 0; j <5; j++){
		 if (arr[i][j]%2==1)
		 	a+=arr[i][j];
		 }
	}
	printf("%d\n",a);
} 	 
int main(){
	create_2d_array();
	}
