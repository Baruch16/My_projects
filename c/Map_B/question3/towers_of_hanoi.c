#include <stdio.h>


void towersofHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		return;
	}
	towersofHanoi(n-1, from_rod, aux_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	towersofHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
	printf("Enter number of disks: ");
	int n;
	scanf("%d", &n);
	towersofHanoi(n, 'A', 'C', 'B'); 
	return 0;
}

