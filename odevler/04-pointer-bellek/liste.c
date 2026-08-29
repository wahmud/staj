#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define  MIN_LIST_SIZE  4

char* liste_read_and_take_row(void)
{
    char temp_row[201];
    char* fgets_ret = fgets(temp_row, 201, stdin);
    if (!fgets_ret) {
        return NULL;
    }
    if (temp_row[strlen(temp_row) - 1] != '\n')
    for (int ch1;(ch1 = getchar()) != '\n' && ch1 != EOF;);
    else
    temp_row[strlen(temp_row) - 1] = '\0';

    size_t size = strlen(temp_row);
    char* row = (char*)malloc(size + 1);
    if (!row) {
        printf("Bellek yetersiz!\n");
        exit(1);
    }
    strcpy(row, temp_row);
    return row;
}

void liste_realloc(char*** p_liste, int cnt)
{
    size_t size_representation;
    char** temp = (char**)realloc(*p_liste, size_representation = (sizeof(char*) * cnt));
    if (temp) {
        *p_liste = temp;
        printf("Bellek alani %zu adede cikarildi:\n", size_representation / (sizeof(char*)));
    }
    else {
        printf("Bellek yetersiz!\n");
        exit(1);
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
                liste_realloc(&liste, is_arrived);
            }
            liste[i] = liste_read_and_take_row();
            if (!liste[i])
                break;
    }
    liste_print_rows(liste, i);

    liste_free_all_so_far(liste, i);

}
