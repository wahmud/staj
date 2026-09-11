#include "dosya.h"
#include "kayit.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    struct Kayit* kayitlar = (struct Kayit*)malloc(sizeof(*kayitlar) * 4);
    int is_arrived = 4;
    int j = kayitlari_oku(&kayitlar, &is_arrived);
    if (j == -1) {
        printf("Bellek alani eklenemedi, program sonlandirildi\n");
        free(kayitlar);
        return 1;
    }

    //ELLE GİRİŞ//
    for (;; ++j) {
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
                    printf("Hatali giris: \";\" karakteri isimde kullanilamaz\n");
            }
            else
                printf("Hatali giris: ad girilmedi!\n");
        }
        //

        if (!fgets_ret1)
            break;
        if (j == is_arrived) {
            is_arrived *= 2;
            void* temp2 = kayit_realloc(&kayitlar, is_arrived);
            if (!temp2) {
                printf("Bellek alani eklenemedi, program sonlandirildi\n");
                free(kayitlar);
                return 1;
            }
        }
        strcpy(k.ad, temp_row_ad);
//////////////////////////////////
        char temp_row_yas[11];
        printf("Yas girin: ");
        char* fgets_ret2 = kayit_fgets(temp_row_yas, 11);
        if (!fgets_ret2) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            free(kayitlar);
            return 1;
        }
        int sscanf_ret = sscanf(temp_row_yas, "%d", &k.yas);
        if (sscanf_ret != 1) {
            printf("Yas icin sayi girilmedi, program sonlandirildi\n");
            free(kayitlar);
            return 1;
        }
////////////////////////////
        char temp_row_tarih[11];
        printf("Tarih girin(gg-aa-yyyy):");
        char* fgets_ret3 = kayit_fgets(temp_row_tarih, 11);
        if (!fgets_ret3) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            free(kayitlar);
            return 1;
        }
        strcpy(k.tarih, temp_row_tarih);
////////////////////////////////////////

        //belleğe ekleme
        kayitlar[j] = k;
    }
    //BİTTİ//
    
    int yazma_ret = kayitlari_yaz(kayitlar, j);
    if (yazma_ret == 1) {
        printf("Dosya acilamadi, program sonlandirildi\n");
        free(kayitlar);
        return 1;
    }


    for (int m = 0; m < j; ++m)
        printf("\n%d. Kayit:\nAd: %s\nYas: %d\nTarih: %s\n", m + 1, kayitlar[m].ad, kayitlar[m].yas, kayitlar[m].tarih);

    free(kayitlar);
}