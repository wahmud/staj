#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    size_t n;
    printf("gireceginiz sayi adedini yazin: ");
    int scanret = scanf("%zu", &n);
    if (scanret <= 0) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (c == EOF) {
            printf("Dosya sonu program sonlandirildi!\n");
            return 1;
        }
        printf("Gecersiz giris yapildi!\n");
        return 1;
    }
    
    long long is_sub = n;
    if (is_sub < 0) {
        printf("Negatif deger girildi!\n");
        return 1;
    }

    int* dizi = (int*)malloc(n * sizeof(*dizi));
    if (!dizi) {
        printf("Bellek yetersiz!\n");
        return 1;
    }

    printf("Sayilari girin:\n");
    for (size_t i = 0; i < n; ++i) {
        int for_scanret = scanf("%d", dizi + i);
        if (for_scanret <= 0) {
            printf("Sayi girisi sekteye ugradi!\n");
            return 1;
        }
    }

    int ch;
    while ((ch = getchar()) != '\n') {
        if (!isspace(ch)) {
            printf("Taahhut edilenden fazla deger girildi!\n");
            return 1;
        }
    }

    printf("Dizi = {\n   ");
    for (size_t i = 0; i < n; ++i) {
        printf("%-2d ", dizi[i]);
    }
    printf("\n}\n");

}