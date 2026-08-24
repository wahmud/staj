#include <stdio.h>
void print_size(int* s, size_t size)
{
    printf("fonksiyonda eleman sayisi = %zu\n", size / sizeof(*s));
}
int main(void)
{
    int sayilar[] = {3, 7, 1, 9, 4};
    printf("eleman sayisi = %zu\n", sizeof(sayilar) / sizeof(*sayilar));

    print_size(sayilar, sizeof(sayilar));
}