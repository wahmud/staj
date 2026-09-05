#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define  MIN_LIST_SIZE  4
#define  TEMP_ROW_SIZE  201

char* liste_fgets_temp_row(char* temp_row)
{
char* fgets_ret = fgets(temp_row, TEMP_ROW_SIZE, stdin);
    if (!fgets_ret) {
        return fgets_ret;
    }
    if (temp_row[strlen(temp_row) - 1] != '\n')
        for (int ch1;(ch1 = getchar()) != '\n' && ch1 != EOF;);
    else
        temp_row[strlen(temp_row) - 1] = '\0';
    return fgets_ret;
}
char* liste_malloc_and_copy_row(char* temp_row)
{
    size_t size = strlen(temp_row);
    char* row = (char*)malloc(size + 1);
    if (!row) {
        return row;;
    }
    strcpy(row, temp_row);
    return row;
}

void* liste_realloc(char*** p_liste, int cnt)
{
    char** temp = (char**)realloc(*p_liste, (sizeof(**p_liste) * cnt));
    if (temp) {
        *p_liste = temp;
        printf("Bellek alani %d adede cikarildi:\n", cnt);
        return temp;
    }
    else {
        return temp;
    }
}

void liste_print_rows(char** liste, int size)
{
    printf("\n%d Adet Satir Girdiniz\nIste Girdiginiz Satirlar:\n", size);
    for (int j = 0; j < size; ++j) {
        printf("%s\n", liste[j]);
    }

}

void liste_free_all_so_far(char** liste, int size)
{
    for (int j = 0; j < size; ++j) {
        free(liste[j]);
    }
    free(liste);

}

int main(void)
{
    char** liste = (char**)malloc(sizeof(*liste) * MIN_LIST_SIZE);
    if (!liste) {
        printf("Bellek yetersiz!\n");
        return 1;
    }
    printf("4 girislik bellek alani var\n");
    printf("Satirlari girin:\n");
    int i;
    int is_arrived = MIN_LIST_SIZE;
    for (i = 0; ; ++i) {
        if (i == is_arrived) {
            is_arrived *= 2;
            void* realloc_ret = liste_realloc(&liste, is_arrived);
            if (!realloc_ret) {
                printf("\nBellek alani buyutulemedi!\nprogram sonlandirildi\n");
                liste_free_all_so_far(liste, i);
                return 1;
            }
        }
        char temp_row[TEMP_ROW_SIZE];
        char* fgets_ret = liste_fgets_temp_row(temp_row);
        if (!fgets_ret) {
            break;
        }
        liste[i] = liste_malloc_and_copy_row(temp_row);

        if (!liste[i]) {
            printf("\nGirilen satir icin bellek alani saglanamadi!\nprogram sonlandirildi.\n");
            liste_free_all_so_far(liste, i);
            return 1;
        }
    }
    liste_print_rows(liste, i);

    liste_free_all_so_far(liste, i);

}