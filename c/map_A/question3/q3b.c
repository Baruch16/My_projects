#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (1) {

		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

int partition_r(int arr[], int low, int high)
{
	srand(time(0));
	int random = low + rand() % (high - low);

	int temp = arr[random];
	arr[random] = arr[low];
	arr[low] = temp;

	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
	printf("1\n");
	if (low < high) {
		int pi = partition_r(arr, low, high);

		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{	srand(time(0));
	int sz;
  	printf("Enter the size of array::");
   	scanf("%d",&sz);
   	int arr[sz],i;
   	for(i=0;i<sz;i++)
     		arr[i]=rand()%100;
     	//int arr[4]={2,2,2,2};
     	printArray(arr,sz);
	quickSort(arr, 0, sz - 1);
	printf("Sorted array: \n");
	printArray(arr, sz);
	return 0;
}

