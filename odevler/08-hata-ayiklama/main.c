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
    char bir_degisken;
    char* fgets_ret_ad = &bir_degisken;
    char* fgets_ret_yas = &bir_degisken;
    char* fgets_ret_tarih = &bir_degisken;
    //ELLE GİRİŞ//
    char bitis[] = "bitti";
    for (;;) {
        struct Kayit k;
//////////////////////////////////////////////AD
        char temp_row_ad[41];
        
        //noktalı virgül ve giriş yok denetimi
        for (;;) {
            printf("Ad girin: ");
            fgets_ret_ad = kayit_fgets(temp_row_ad, 41);
            if (!fgets_ret_ad) {
                printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
                break;
            }
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
        //bitti

        //\r kontrolü
            char* carriage_return1 = strchr(temp_row_ad, '\r');
            if(carriage_return1)
                *carriage_return1 = '\0';
        //bitti

        if (!fgets_ret_ad)
            break;
        if (!strcmp(bitis, temp_row_ad)) {
            fgets_ret_yas = (char*)1;
            fgets_ret_tarih = (char*)1;
            break;
        }

        strcpy(k.ad, temp_row_ad);
//////////////////////////////////////////YAŞ
        char temp_row_yas[11];
        for (;;) {
            printf("Yas girin: ");
            fgets_ret_yas = kayit_fgets(temp_row_yas, 11);
            if (!fgets_ret_yas) {
                printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
                break;
            }
            int sscanf_ret = sscanf(temp_row_yas, "%d", &k.yas);
            if (sscanf_ret == 1)
                break;
            else
                printf("Hatali giris, yas icin sayi girilmedi\n");
        }

        if (!fgets_ret_yas)
            break;
///////////////////////////////////////TARİH
        char temp_row_tarih[11];
        printf("Tarih girin(gg-aa-yyyy):");
        fgets_ret_tarih = kayit_fgets(temp_row_tarih, 11);
        if (!fgets_ret_tarih) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            break;
        }
        
        //\r kontrolü
        char* carriage_return2 = strchr(temp_row_tarih, '\r');
        if(carriage_return2)
        *carriage_return2 = '\0';
        //bitti
        strcpy(k.tarih, temp_row_tarih);
////////////////////////////////////////BİTTİ

        //belleğe ekleme
        struct Dugum* dugum_ekle_ret = dugum_ekle(bas_pointer, k);
        if (!dugum_ekle_ret) {
            printf("Bellek alani eklenemedi, program sonlandirildi\n");
            liste_bosalt(bas_pointer);
            return 1;
        }
        //bitti
    }
    //BİTTİ

    //arama
    char* fgets_ret_arama = NULL;
    if (fgets_ret_ad && fgets_ret_yas && fgets_ret_tarih) {
        char temp_ad_arama[41];
        printf("Aradiginiz kaydi girin:\n");
        fgets_ret_arama = kayit_fgets(temp_ad_arama, 41);
        if (!fgets_ret_arama) {
            printf("Dosya sonu, arama yapilamiyor\n");
        }
        else {

            //\r kontrolü
            char* carriage_return3 = strchr(temp_ad_arama, '\r');
            if(carriage_return3)
                *carriage_return3 = '\0';
            //bitti

            struct Dugum* aranan_dugum = liste_ara(*bas_pointer, temp_ad_arama);
            if (!aranan_dugum) {
                printf("Aranan kayit bulunamadi\n");
            }
            else {
                printf("Aranan kayit bulundu:\n");
                printf("Ad: %s\nYas: %d\nTarih: %s\n", aranan_dugum->kayit.ad, aranan_dugum->kayit.yas, aranan_dugum->kayit.tarih);
            }

        }
    }
    //bitti

    //silme
    if (fgets_ret_arama) {
        printf("Silmek istediginiz kaydi girin:\n");
        char temp_silme[41];
        char* fgets_ret_silme = kayit_fgets(temp_silme,41);
        if (!fgets_ret_silme)
            printf("Dosya sonu, silme islemi yapilamiyor.");
        else {
            //\r kontrolü
            char* carriage_return4 = strchr(temp_silme, '\r');
            if(carriage_return4)
                *carriage_return4 = '\0';
            //bitti
            int silme_ret = liste_sil(bas_pointer, temp_silme);
            if (silme_ret)
                printf("Bu kayit bulunamadi\n");
            else
                printf("Kayit silindi\n");
        }
    }
    //bitti

        
    //dosyaya yazma
    int yazma_ret = kayitlari_yaz(*bas_pointer);
    if (yazma_ret == 1) {
        printf("Dosya acilamadi, program sonlandirildi\n");
        liste_bosalt(bas_pointer);
        return 1;
    }

    liste_bas(*bas_pointer);
    liste_bosalt(bas_pointer);
    
}