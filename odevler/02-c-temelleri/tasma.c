#include <stdio.h>
int main(void)
{
    int x = 2147483647;
    printf("%d\n", x);
    printf("bir artirildi\n");
    ++x;
    printf("%d\n", x);
    printf("\n");
    unsigned int y = 4294967295;
    printf("%u\n", y);
    printf("bir artirildi\n");
    printf("%u\n", ++y);
    
}