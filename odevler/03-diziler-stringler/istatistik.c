#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char metin[201];
    printf("metni girin:\n");
    char* fgets_ret = fgets(metin, 201, stdin);
    if (!fgets_ret) {
        printf("dosya sonu program sonlandirildi\n");
        exit(0);
    }
    
    if (strlen(metin) == 200 && metin[strlen(metin) - 1] != '\n') {
        for (int c; (c = getchar()) != '\n' && c != EOF;);
    }
    else {
        metin[strlen(metin) - 1] = '\0';
    }
    //printf("%s\n", metin);

 
    // int alpha_cnt = 0;
    // int digit_cnt = 0;
    // int space_cnt = 0;
    // int total_cnt = 0;
    // for (int i = 0; metin[i] != '\0'; ++i) {
    //     alpha_cnt += !!isalpha(metin[i]);
    //     digit_cnt += !!isdigit(metin[i]);
    //     space_cnt += !!isspace(metin[i]);
    //     ++total_cnt;
    // }
    // printf("harf sayisi   = %d\n", alpha_cnt);
    // printf("rakam sayisi  = %d\n", digit_cnt);
    // printf("bosluk sayisi = %d\n", space_cnt);
    // printf("toplam karakter sayisi   = %d\n", total_cnt);
    int alpha_cnt = 0;
    int digit_cnt = 0;
    int space_cnt = 0;
    int total_cnt = 0;
    for (int i = 0; i < strlen(metin); ++i) {
        alpha_cnt += !!isalpha(metin[i]);
        digit_cnt += !!isdigit(metin[i]);
        space_cnt += !!isspace(metin[i]);
        ++total_cnt;
    }
    printf("harf sayisi   = %d\n", alpha_cnt);
    printf("rakam sayisi  = %d\n", digit_cnt);
    printf("bosluk sayisi = %d\n", space_cnt);
    printf("toplam karakter sayisi   = %d\n", total_cnt);



}
