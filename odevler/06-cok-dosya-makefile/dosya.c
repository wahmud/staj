#include <stdio.h>
#include "kayit.h"
#include "dosya.h"
int kayitlari_oku(struct Kayit** p_kayitlar, int* p_kapasite)
{ 
    struct Kayit k;
    int j = 0;
    *p_kapasite = 4;
    FILE* f_ = fopen("kayitlar.txt", "r");
    if (f_) {
        for (j = 0;;) {
            char satir[60];
            char* fgets_ret = fgets(satir, 60, f_);
            if (!fgets_ret)
                break;
            if (j == *p_kapasite) {
                *p_kapasite *= 2;
                void* temp1 = kayit_realloc(p_kayitlar, *p_kapasite);
                if (!temp1)
                    return -1;
            }
            int sscan_ret = sscanf(satir, "%40[^;];%d;%10[^\n]", k.ad, &k.yas, k.tarih);
            if (sscan_ret == 3) {
                //belleğe ekleme
                (*p_kayitlar)[j] = k;
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
int kayitlari_yaz(struct Kayit* kayitlar, int adet)
{
    int i;
    FILE* f = fopen("kayitlar.txt", "w");
    if (!f)
        return 1;
    for (i = 0; i < adet; ++i)
        fprintf(f, "%s;%d;%s\n", kayitlar[i].ad, kayitlar[i].yas, kayitlar[i].tarih);
    fclose(f);
    return 0;
}