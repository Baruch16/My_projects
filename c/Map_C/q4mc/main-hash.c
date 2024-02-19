#include "hash.h"
#include <stdio.h>
int main()
{
    install("consider", "value 1");
    install("three", "value 2");
    install("less", "value 3");
    install("taxes", "value 4");
    printHashtable();
    printf("Removing three\n");
    undef("three");
    printHashtable();
    return 0;
    }
