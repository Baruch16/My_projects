#include "q6.h"
#include <stdio.h>
#include <limits.h>


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

int divisor(int array[])
{ 
    int sum_start = 0, sum_end = 0, start_ptr = 0, end_ptr = SIZE-1, start_move = 1, end_move = 1;


    while(end_ptr - start_ptr != 1)
    {
        if(start_move)
            sum_start += array[start_ptr];
        if(end_move)
            sum_end += array[end_ptr];

        if (sum_start > sum_end)
        {
            --end_ptr;
            start_move = 0;
            end_move = 1;
        }
        else
        {
            ++start_ptr;
            start_move = 1;
            end_move = 0;
        }
    }

   
    if (sum_start == sum_end)
        return start_ptr;
    else
        return -1;
}


