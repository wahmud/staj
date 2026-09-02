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
    
    
    int j = 0;
    int is_arrived = 4;
    FILE* f_ = fopen("kayitlar.txt", "r");
    if (!f_) {
        printf("Dosya acilamadi, program sonlandirildi\n");
        free(kayitlar);
        return 1;
    }
    for (j = 0;; ++j) {
        char satir[56];
        char* fgets_ret = fgets(satir, 56, f_);
        if (!fgets_ret)
            break;
        if (j == is_arrived) {
            is_arrived *= 2;
            void* temp = kayit_realloc(&kayitlar, is_arrived);
            if (!temp) {
                printf("Bellek alani eklenemedi, program sonlandirildi\n");
                free(kayitlar);
                return 1;
            }
        }
        int sscan_ret = sscanf(satir, "%40[^;];%d;%10[^\n]", k.ad, &k.yas, k.tarih);
        if (sscan_ret == 3)
            kayitlar[j] = k;
        else {
            --j;
        }

    }
    fclose(f_);


    int i;
    FILE* f = fopen("kayitlar.txt", "w");
    if (!f) {
        printf("Dosya acilamadi, program sonlandirildi\n");
        free(kayitlar);
        return 1;
    }
    for (i = 0; j && i < j; ++i) {
        fprintf(f, "%s;%d;%s\n", kayitlar[i].ad, kayitlar[i].yas, kayitlar[i].tarih);
    }
    fclose(f);

    for (int j = 0; j < i; ++j) {
        printf("\n%d. Kayit:\nAd: %s\nYas: %d\nTarih: %s\n", j + 1, kayitlar[j].ad, kayitlar[j].yas, kayitlar[j].tarih);
    }

    free(kayitlar);
}