#include <stdio.h>
size_t get_size(int* a)
{
    return sizeof(a) / sizeof(a[0]);
}
int main(void)
{
    int sayilar[] = {3, 7, 1, 9, 4};
    printf("eleman sayisi = %zu\n", sizeof(sayilar) / sizeof(sayilar[0]));
    printf("eleman sayisi = %zu\n", get_size(sayilar));
}