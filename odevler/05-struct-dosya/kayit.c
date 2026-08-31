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


    struct Kayit* kayitlar = (struct Kayit*)malloc(sizeof(*kayitlar) * 4);
    if (!kayitlar) {
        printf("Bellek yetersiz!\n");
        return 1;
    }
    printf("4 kayitlik bellek alani var\n");
    int is_arrived = 4;
    int i;
    for (i = 0;; ++i) {
        ////////
        char temp_row_ad[41];
        printf("Ad girin: ");
        char* fgets_ret1 = fgets(temp_row_ad, 41, stdin);
        if (!fgets_ret1)
            break;
        //realloc
        if (i == is_arrived) {
            is_arrived *= 2;
            void* temp = realloc(kayitlar, sizeof(*kayitlar) * is_arrived);
            if (!temp) {
                printf("Bellek alani eklenemedi, program sonlandirildi\n");
                free(kayitlar);
                return 1;
            }
            printf("Bellek alani %d adet kayita yukseltildi.\n", is_arrived);
            kayitlar = temp;
        }
        ////////
        if (temp_row_ad[strlen(temp_row_ad) - 1] != '\n') {
            for (int ch; (ch = getchar()) != '\n' && ch != EOF;);
        }
        else {
            temp_row_ad[strlen(temp_row_ad) - 1] = '\0';
        }
        strcpy(kayitlar[i].ad, temp_row_ad);
        //////////
        char temp_row_yas[10];
        printf("Yas girin: ");
        char* fgets_ret2 = fgets(temp_row_yas, 10, stdin);
        if (!fgets_ret2) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            free(kayitlar);
            return 1;
        }
        if (temp_row_yas[strlen(temp_row_yas) - 1] != '\n') {
            for (int ch; (ch = getchar()) != '\n' && ch != EOF;);
        }
        else {
            temp_row_yas[strlen(temp_row_yas) - 1] = '\0';
        }
        int sscanf_ret = sscanf(temp_row_yas, "%d", &kayitlar[i].yas);
        if (!sscanf_ret) {
            printf("Yas icin sayi girilmedi, program sonlandirildi\n");
            free(kayitlar);
            return 1;
        }
        ///////////
        char temp_row_tarih[11];
        printf("Tarih girin(gg-aa-yyyy):");
        char* fgets_ret3 = fgets(temp_row_tarih, 11, stdin);
        if (!fgets_ret3) {
            printf("Dosya sonu, giris tamamlanmadi, program sonlandirildi\n");
            free(kayitlar);
            return 1;
        }
        if (temp_row_tarih[strlen(temp_row_tarih) - 1] != '\n') {
            for (int ch; (ch = getchar()) != '\n' && ch != EOF;);
        }
        else {
            temp_row_tarih[strlen(temp_row_tarih) - 1] = '\0';
        }
        strcpy(kayitlar[i].tarih, temp_row_tarih);
        ///////////
    }

    for (int j = 0; j < i; ++j) {
        printf("\n%d. Kayit:\nAd: %s\nYas: %d\nTarih: %s\n", j + 1, kayitlar[j].ad, kayitlar[j].yas, kayitlar[j].tarih);
    }
    free(kayitlar);
}