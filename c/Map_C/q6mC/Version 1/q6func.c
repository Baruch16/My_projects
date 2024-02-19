
#include <stdio.h>
#include <limits.h>
#define SIZE 6

void check_biggest_prod(int array[])
{
    int max1, max2 = INT_MIN;
    int min1, min2 = INT_MAX;
    for (int i = 0; i <SIZE; i++)
    {
        if (max1 < array[i])
        {
            max2 = max1;
            max1 = array[i];
        }
        else if (max2 < array[i])
        {
            max2 = array[i];
        }

        if (min1 > array[i])
        {
            min2 = min1;
            min1 = array[i];
        }
        else if (min2 > array[i])
        {
            min2 = array[i];
        }
    }
    int product;
    if (max1 * max2 > min1 * min2)
        product = max1 * max2;
    else if (min1 * min2 > max1 * max2)
        product = min1 * min2;
    printf("%d\n", product);
}

void divisor(int array[])
{
    int i, j, sum_a, sum_b;
    i = 0;
    j = SIZE - 1;
    sum_a=array[i];
    sum_b=array[j-1];
    while (i < j)
    {
        
        if (sum_a <= sum_b)
        {   sum_a += array[i];
            i++;
        }
        else if (sum_b<sum_a){
            sum_b += array[j];
            j--;
        }
            
       
    }
     if (sum_a == sum_b)
            printf("%d", array[i + 1]);
    else
         printf("None");
}

