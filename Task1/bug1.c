#include <stdio.h>

int main()
{
    int num = 3;
    int *ptr = (int *)0xdeadbeef;  
    *ptr = num;  //we are writing to an invalid address.
    printf("%d", num);

    return 0;
}
