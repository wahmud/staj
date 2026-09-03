#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Kayit {
    char ad[41];
    int yas;
    char tarih[11];
};

void kayit_set_value(struct Kayit k)
{
    k.yas = 82;
}

void kayit_set_pointer(struct Kayit* p)
{
    p->yas = 82;
}




int main(void)
{
    struct Kayit k;
    strcpy(k.ad, "Mahmut");
    k.yas = 24;
    strcpy(k.tarih, "5-5-2002");
    printf("asil yas = %d\n", k.yas);
    kayit_set_value(k);
    printf("set_value\n");
    printf("yas = %d\n", k.yas);
    kayit_set_pointer(&k);
    printf("set_pointer\n");
    printf("yas = %d\n", k.yas);
    printf("\n\n");

    printf("uc elemanin sizeoflari: %zu + %zu + %zu\n", sizeof(k.ad), sizeof(k.yas), sizeof(k.tarih));
    printf("yapinin boyutu: %zu\n", sizeof(struct Kayit));

}