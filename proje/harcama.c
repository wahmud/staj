#include "harcama.h"
#include "liste.h"
#include "tarih.h"
#include "dosya.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int komut_dogrulama(int argc, char** argv)
{
    if (argc == 5) {
        for (int i = 0; i < 5; ++i) 
            for (int j = 0; j < strlen(argv[i]); ++j) 
                if (isspace(argv[i][j]))
                    return -1;
        if (strcmp(argv[0], "./harcama"))
            return 0;
        else if (strcmp(argv[1], "ekle"))
            return 0;
        else if (!gecerli_gun_tarihi_mi(argv[2]))
            return 11;
        else if (!gecerli_kat_mi(argv[3]))
            return 12;
        else {
            double temp = 0.;
            int sscanf_ret1 = sscanf(argv[4], "%lf", &temp);
            if (sscanf_ret1 == 0)
                return 13;
            else if (temp != (int)temp)
                return 14;
            else if (temp == 0.)
                return 15;
            else if (temp < 0.)
                return 16;
            else if (temp > 10000.)
                return 17;
            else
                return 1;
        }
    }
    else if (argc == 3) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < strlen(argv[i]); ++j)
                if (isspace(argv[i][j]))
                    return -1;
        if (strcmp(argv[0], "./harcama"))
            return 0;
        else if (!strcmp(argv[1], "liste")) {
            if (!gecerli_ay_tarihi_mi(argv[2]))
                return 21;
            else
                return 2;
        }
        else if (!strcmp(argv[1], "ozet")) {
            if (!gecerli_ay_tarihi_mi(argv[2]))
                return 31;
            else
                return 3;
        }
        else
            return 0;
    }
    else
        return 0;
}
int dosyadan_ekrana_basma(char* ay_tarihi)
{
    printf("dosyadan_ekrana_basma cagirildi\n");
    return 0;
}
int dosyadan_kategori_okuma_ve_siralama(struct Kategoriler**)
{
    printf("kategori_doldurma_ve_siralama cagirildi\n");
    return 0;
}
void kategori_ozeti_ekrana_basma(struct Kategoriler*)
{
    printf("kategori_ozeti_ekrana_basma cagirildi\n");
}
int gecerli_kat_mi(char* kategori)
{
    if (strlen(kategori) > 20)
        return 0;
    else if (strchr(kategori, ' '))
        return 0;
    else
        return 1;
}
