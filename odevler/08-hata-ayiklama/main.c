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
    char bitis[] = "bitti";
    for (;;) {
        struct Kayit k;
//////////////////////////////////////////////AD
        char temp_row_ad[41];
        char* fgets_ret1;
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
        //bitti
        if (!fgets_ret1 || !strcmp(bitis, temp_row_ad))
            break;

        strcpy(k.ad, temp_row_ad);
//////////////////////////////////////////YAŞ
        char temp_row_yas[11];
        char* fgets_ret2;
        for (;;) {
            printf("Yas girin: ");
            fgets_ret2 = kayit_fgets(temp_row_yas, 11);
            if (!fgets_ret2) {
                printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
                break;
            }
            int sscanf_ret = sscanf(temp_row_yas, "%d", &k.yas);
            if (sscanf_ret == 1)
                break;
            else
                printf("Hatali giris, yas icin sayi girilmedi\n");
        }
        if (!fgets_ret2)
            break;
///////////////////////////////////////TARİH
        char temp_row_tarih[11];
        printf("Tarih girin(gg-aa-yyyy):");
        char* fgets_ret3 = kayit_fgets(temp_row_tarih, 11);
        if (!fgets_ret3) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            break;
        }
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
    char temp_ad_arama[41];
    printf("Aradiginiz kaydi girin:\n");
    char* fgets_ret_arama = kayit_fgets(temp_ad_arama, 41);
    if (!fgets_ret_arama) {
        printf("Dosya sonu, arama yapilamiyor\n");
    }
    else {

        struct Dugum* aranan_dugum = liste_ara(*bas_pointer, temp_ad_arama);
        if (!aranan_dugum) {
            printf("Aranan kayit bulunamadi\n");
        }
        else {
            printf("Aranan kayit bulundu:\n");
            printf("Ad: %s\nYas: %d\nTarih: %s\n", aranan_dugum->kayit.ad, aranan_dugum->kayit.yas, aranan_dugum->kayit.tarih);
        }

    }
    //bitti

    //silme
    printf("Silmek istediginiz kaydi girin:\n");
    char temp_silme[41];
    char* fgets_ret_silme = kayit_fgets(temp_silme,41);
    if (!fgets_ret_silme)
        printf("Dosya sonu, silme islemi yapilamiyor.");
    else {
        int silme_ret = liste_sil(bas_pointer, temp_silme);
        if (silme_ret)
            printf("Bu kayit bulunamadi\n");
        else
            printf("Kayit silindi\n");
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