#include "dosya.h"
#include "kayit.h"
#include "liste.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    struct Dugum* dugum = NULL;
    struct Dugum** bas_pointer = &dugum;
    int j = kayitlari_oku(bas_pointer);
    if (j == -1) {
        printf("Bellek alani eklenemedi, program sonlandirildi\n");
        liste_bosalt(bas_pointer);
        return 1;
        
    }

    //ELLE GİRİŞ//
    for (;;) {
        struct Kayit k;
        char* fgets_ret1;
        char temp_row_ad[41];
        //noktalı virgül ve giriş yok denetimi
        for (;;) {
            printf("Ad girin: ");
            fgets_ret1 = kayit_fgets(temp_row_ad, 41);
            if (!fgets_ret1)
                break;
            if (*temp_row_ad != '\0') {
                char* strchr_ret = strchr(temp_row_ad, ';');
                if (!strchr_ret)
                    break;
                else
                    printf("Hatali giris, \";\" karakteri isimde kullanilamaz\n");
            }
            else
                printf("Hatali giris, ad girilmedi\n");
        }
        //


        if (!fgets_ret1)
            break;

        strcpy(k.ad, temp_row_ad);
//////////////////////////////////
        char temp_row_yas[11];
        printf("Yas girin: ");
        char* fgets_ret2 = kayit_fgets(temp_row_yas, 11);
        if (!fgets_ret2) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            liste_bosalt(bas_pointer);
            return 1;
        }
        int sscanf_ret = sscanf(temp_row_yas, "%d", &k.yas);
        if (sscanf_ret != 1) {
            printf("Yas icin sayi girilmedi, program sonlandirildi\n");
            liste_bosalt(bas_pointer);
            return 1;
        }
////////////////////////////
        char temp_row_tarih[11];
        printf("Tarih girin(gg-aa-yyyy):");
        char* fgets_ret3 = kayit_fgets(temp_row_tarih, 11);
        if (!fgets_ret3) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            liste_bosalt(bas_pointer);
            return 1;
        }
        strcpy(k.tarih, temp_row_tarih);
////////////////////////////////////////

        //belleğe ekleme
        struct Dugum* dugum_ekle_ret = dugum_ekle(bas_pointer, k);
        if (!dugum_ekle_ret) {
            printf("Bellek alani eklenemedi, program sonlandirildi\n");
            liste_bosalt(bas_pointer);
            return 1;
        }
        ++j;
    }
    //BİTTİ
    int yazma_ret = kayitlari_yaz(*bas_pointer, j);
    if (yazma_ret == 1) {
        printf("Dosya acilamadi, program sonlandirildi\n");
        liste_bosalt(bas_pointer);
        return 1;
    }

    liste_bas(*bas_pointer);
    liste_bosalt(bas_pointer);
    
}