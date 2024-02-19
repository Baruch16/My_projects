
#include <math.h>
#include <stdio.h>
#define ARRAY_SIZE 10

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


void reverse(int Array[ARRAY_SIZE])
{
	int temp,i;
	for ( i=0; i < (ARRAY_SIZE/2) ; i++)
	{
	temp = Array[ARRAY_SIZE-1-i];
	Array[ARRAY_SIZE-1-i] = Array[i];
	Array[i] =temp;
	}
	}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
	printf("%d ", arr[i]);

	printf("\n");
}


int main()
{
	int i, Array[ARRAY_SIZE];
	printf(" Enter elements into the Array :n ");
	for (i=0; i< ARRAY_SIZE ; i++)
	{
	printf("Enter %2d elements : ",i);
	scanf("%d",&Array[i]);
	}
	printf("n************************nn");
	insertionSort(Array,ARRAY_SIZE);
	reverse(Array);
	printf("************************nn");
	printf(" here is the new Array : n ");
	for (i=0; i< ARRAY_SIZE ; i++)
	{
	printf("%4d",Array[i]);
	}
	return 0;
	}
