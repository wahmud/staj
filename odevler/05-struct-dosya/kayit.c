#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Kayit {
    char ad[41];
    int yas;
    char tarih[11];
};

void* kayit_realloc(struct Kayit** p, int size)
{
    void* temp = realloc(*p, size * sizeof(**p));
    if (temp) {
        *p = temp;
        printf("Bellek alani %d adet kayita yukseltildi.\n", size);
        return temp;
    }
    else {
        return temp;
    }
}

char* kayit_fgets(char* temp, int size)
{
    char* fgets_ret = fgets(temp, size, stdin);
    if (!fgets_ret)
        return fgets_ret;
    if (temp[strlen(temp) - 1] != '\n')
        for (int ch; (ch = getchar()) != '\n' && ch != EOF;);
    else
        temp[strlen(temp) - 1] = '\0';
    return temp;    
}


int main(void)
{
    struct Kayit k;
    struct Kayit* kayitlar = (struct Kayit*)malloc(sizeof(*kayitlar) * 4);
    if (!kayitlar) {
        printf("Bellek yetersiz!\n");
        return 1;
    }
    printf("4 kayitlik bellek alani var\n");
    
    //DOSYADAN OKUMA//
    int j = 0;
    int is_arrived = 4;
    FILE* f_ = fopen("kayitlar.txt", "r");
    if (f_) {
        for (j = 0;; ++j) {
            char satir[60];
            char* fgets_ret = fgets(satir, 60, f_);
            if (!fgets_ret)
                break;
            if (j == is_arrived) {
                is_arrived *= 2;
                void* temp1 = kayit_realloc(&kayitlar, is_arrived);
                if (!temp1) {
                    printf("Bellek alani eklenemedi, program sonlandirildi\n");
                    free(kayitlar);
                    return 1;
                }
            }
            int sscan_ret = sscanf(satir, "%40[^;];%d;%10[^\n]", k.ad, &k.yas, k.tarih);
            if (sscan_ret == 3)
                //belleğe ekleme
                kayitlar[j] = k;
            else {
                strcpy(k.ad, "");
                kayitlar[j] = k;
            }
        }
        fclose(f_);
    }
    //BİTTİ//




    //ELLE GİRİŞ//
    for (;; ++j) {
        char temp_row_ad[41];
        printf("Ad girin: ");
        char* fgets_ret1 = kayit_fgets(temp_row_ad, 41);
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
        char temp_row_yas[3];
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


    //DOSYAYA YAZMA//
    int i;
    FILE* f = fopen("kayitlar.txt", "w");
    if (!f) {
        printf("Dosya acilamadi, program sonlandirildi\n");
        free(kayitlar);
        return 1;
    }
    for (i = 0; j && i < j; ++i) {
        if (*kayitlar[i].ad)
            fprintf(f, "%s;%d;%s\n", kayitlar[i].ad, kayitlar[i].yas, kayitlar[i].tarih);        
    }
    fclose(f);
    //BİTTİ//

    for (int k = 0; k < j; ++k) {
        if (*kayitlar[k].ad)
            printf("\n%d. Kayit:\nAd: %s\nYas: %d\nTarih: %s\n", k + 1, kayitlar[k].ad, kayitlar[k].yas, kayitlar[k].tarih);
        else
            printf("\n%d. Kayit:\nGecersiz giris\n", k + 1);
    }

    free(kayitlar);
}