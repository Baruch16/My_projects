#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "q2.h"


void insert(char *arg){
	stack[stk_ptr++]=atoi(arg);
}

void calculate(char op){

	int num1, num2, result;
	num1 = stack[stk_ptr-1];
    	--stk_ptr;
    	num2 = stack[stk_ptr-1];
    	--stk_ptr;
    
    	switch (op)
    	{
    	case ('+'):
        	result = num1 + num2;
        	break;
    	case ('-'):
        	result = num1 - num2;
        	break;
    	case ('x'):
        	result = num1 * num2;
        	break;
    	case ('/'):
        	result = num1 / num2;
        	break;
    
    	default:
        	return;
    }

    stack[stk_ptr++] = result;
 }
 
void print_result()
{
    printf("The result is: %d\n", stack[stk_ptr-1]);
 }
 







 
