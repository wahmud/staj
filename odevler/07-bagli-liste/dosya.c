#include <stdio.h>
#include "kayit.h"
#include "dosya.h"
#include "liste.h"
int kayitlari_oku(struct Dugum** dugum_2)
{
    int j = 0;
    FILE* f_ = fopen("kayitlar.txt", "r");
    struct Dugum dugum;
    struct Dugum* dugum_ekle_ret;
    if (f_) {
        for (j = 0;;) {
            char satir[60];
            char* fgets_ret = fgets(satir, 60, f_);
            if (!fgets_ret)
                break;
            int sscan_ret = sscanf(satir, "%40[^;];%d;%10[^\n]", dugum.kayit.ad, &dugum.kayit.yas, dugum.kayit.tarih);
            if (sscan_ret == 3) {
                dugum_ekle_ret = dugum_ekle(dugum_2, dugum.kayit);
                if (!dugum_ekle_ret) {
                    liste_bosalt(dugum_2);
                    return -1;
                }
                ++j;
            }
            else {
                printf("Bozuk satir atlandi: %s", satir);
            }
        }
        fclose(f_);
        return j;
    }
    else
        return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

int kayitlari_yaz(struct Dugum* dugum_1, int adet)
{
    int i;
    FILE* f = fopen("kayitlar.txt", "w");
    if (!f)
        return 1;
    for (i = 0; i < adet; ++i) {
        fprintf(f, "%s;%d;%s\n", dugum_1->kayit.ad, dugum_1->kayit.yas, dugum_1->kayit.tarih);
        dugum_1 = dugum_1->sonraki;
    }
    fclose(f);
    return 0;
}