#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void print_types_of_chars_on_str(char* m)
{
int alpha_cnt = 0;
    int digit_cnt = 0;
    int space_cnt = 0;
    int total_cnt = 0;
    for (int i = 0; m[i] != '\0'; ++i) {
        alpha_cnt += !!isalpha(m[i]);
        digit_cnt += !!isdigit(m[i]);
        space_cnt += !!isspace(m[i]);
        ++total_cnt;
    }
    printf("harf sayisi   = %d\n", alpha_cnt);
    printf("rakam sayisi  = %d\n", digit_cnt);
    printf("bosluk sayisi = %d\n", space_cnt);
    printf("toplam karakter sayisi   = %d\n", total_cnt);
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void print_num_of_words_on_str(char * m)
{
int word_cnt = 0;
    for (int i = 1; i < strlen(m); ++i) {
        int is_space = 0;
        is_space = m[i - 1] == ' ';
        if (is_space && (isalpha(m[i]) || isdigit(m[i]))) {
            ++word_cnt;
        }
        else if (i == 1 && (isalpha(m[i - 1]) || isdigit(m[i - 1]))) {
            ++word_cnt;
        }
    }
    printf("kelime sayisi = %d\n", word_cnt);
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void print_freqs_of_letters_on_str(char* m)
{
    int sayac[26] = { 0 };
    for (int i = 0; i < strlen(m); ++i) {
        if (isalpha(m[i]))
            ++sayac[tolower(m[i]) - 'a'];
    }
    printf("Metnin harf frekansi:\n");
    for (int i = 0; i < 26; ++i) {
        if (sayac[i])
            printf("%c: %d\n", 'a' + i, sayac[i]);
    }
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void print_longest_word_on_str(char* m)
{
char en_uzun[201];
    int kelime_indeksi = 0;
    int kelime_boyutu = 0;
    int temp_cnt = 0;
    for (int i = 0; i < strlen(m) + 1; ++i) {
        if ((isalpha(m[i]) || isdigit(m[i]))) 
            ++temp_cnt;
        else {
            if (kelime_boyutu < temp_cnt) {
                kelime_boyutu = temp_cnt;
                kelime_indeksi = i - temp_cnt;
            }
            temp_cnt = 0;
        }
    }
    strncpy(en_uzun, m + kelime_indeksi, kelime_boyutu);
    en_uzun[kelime_boyutu] = '\0';
    printf("en uzun kelime:\n%s\n", en_uzun);
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

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

    printf("\n\n");
    print_types_of_chars_on_str(metin);
    printf("\n\n");

    print_num_of_words_on_str(metin);
    printf("\n\n");

    print_freqs_of_letters_on_str(metin);
    printf("\n\n");
    
    print_longest_word_on_str(metin);
}
