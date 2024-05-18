#include <stdio.h>

int main()
{
    int num = 3;
    int *ptr = (int *)0xdeadbeef;  
    *ptr = num;  
    printf("%d", num);

    return 0;
}
