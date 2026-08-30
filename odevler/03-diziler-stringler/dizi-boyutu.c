#include <stdio.h>
void print_size_wrong(int* s)
{
    printf("fonksiyonda eleman sayisi = %zu(yanlis)\n", sizeof(s) / sizeof(*s));
}


void print_size_correct(int* s, size_t size)
{
    printf("fonksiyonda eleman sayisi = %zu\n", size / sizeof(*s));
}

int main(void)
{
    int sayilar[] = {3, 7, 1, 9, 4};
    printf("eleman sayisi = %zu\n", sizeof(sayilar) / sizeof(*sayilar));
    
    print_size_wrong(sayilar);

    print_size_correct(sayilar, sizeof(sayilar));


}