#include <stdio.h>
#include "kayit.h"
#include "dosya.h"
#include "liste.h"
int kayitlari_oku(struct Dugum** dugum_2)
{
    FILE* f_ = fopen("kayitlar.txt", "r");
    struct Dugum dugum;
    if (f_) {
        for (;;) {
            char satir[60];
            char* fgets_ret = fgets(satir, 60, f_);
            if (!fgets_ret)
                break;
            int sscan_ret = sscanf(satir, "%40[^;];%d;%10[^\n]", dugum.kayit.ad, &dugum.kayit.yas, dugum.kayit.tarih);
            if (sscan_ret == 3) {
                struct Dugum* dugum_ekle_ret = dugum_ekle(dugum_2, dugum.kayit);
                if (!dugum_ekle_ret) {
                    liste_bosalt(dugum_2);
                    fclose(f_);
                    return -1;
                }
            }
            else {
                printf("Bozuk satir atlandi: %s", satir);
            }
        }
        fclose(f_);
        return 0;
    }
    else
        return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

int kayitlari_yaz(struct Dugum* dugum_1)
{
    FILE* f = fopen("kayitlar.txt", "w");
    if (!f)
        return 1;
    for (; dugum_1 != NULL;) {
        fprintf(f, "%s;%d;%s\n", dugum_1->kayit.ad, dugum_1->kayit.yas, dugum_1->kayit.tarih);
        dugum_1 = dugum_1->sonraki;
    }
    fclose(f);
    return 0;
}