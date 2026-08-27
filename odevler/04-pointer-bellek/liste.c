#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define  MIN_LIST_SIZE  4
int liste_loop_asist(int i)
{
    static int is_arrived = MIN_LIST_SIZE;
    if (is_arrived == i) {
        is_arrived *= 2;
        return 1;
    }
    return 0;
}

size_t liste_realloc_size_asist(void)
{
    static size_t cnt = sizeof(char*) * MIN_LIST_SIZE;
    cnt *= 2;
    return cnt;
}

char* liste_read_and_take_row(void)
{
    char temp_row[201];
    char* fgets_ret = fgets(temp_row, 201, stdin);
    if (!fgets_ret) {
        printf("Dosya sonu program sonlandirildi\n");
        exit(1);
    }
    size_t size = strlen(temp_row);
    if (temp_row[size - 1] != '\n')
    for (int ch1;(ch1 = getchar()) != '\n' && ch1 != EOF;);
    else
    temp_row[size - 1] = '\0';
    
    char* row = (char*)malloc(size + 1);
    if (!row) {
        printf("Bellek yetersiz!\n");
        exit(1);
    }
    strcpy(row, temp_row);
    return row;
}

void liste_realloc(char*** p_liste)
{
    size_t size_representation;
    char** temp = (char**)realloc(*p_liste, size_representation = liste_realloc_size_asist());
    if (temp) {
        *p_liste = temp;
        printf("%zu adede kadar giris yapabilirsiniz:\n", size_representation / 16);
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
    
    int i;
    int init_flag = 1;
    for (i = 0; ; ++i) {
        int ch_ = 0;
        if (!init_flag) {
            printf("Daha giris yapmak istiyor musunuz? (e/h):");
            while ((ch_ = getchar()) != 'e' && ch_ != 'h' && ch_ != EOF) {
                for (;(ch_ = getchar()) != '\n';);
                printf("Daha giris yapmak istiyor musunuz? (e/h):");
            }
            for (int ch2; (ch2 = getchar()) != '\n' && ch2 != EOF;);
        }
        
        if (ch_ == 'e' || init_flag == 1) {
            printf("Giris yapin:\n");
            if (liste_loop_asist(i)) {
                liste_realloc(&liste);
            }
            liste[i] = liste_read_and_take_row();
        }
        else if (ch_ == 'h')
            break;
        else {
            printf("Dosya sonu program sonlandirildi\n");
            liste_free_all_so_far(liste, i);
            return 1;
        }
        init_flag = 0;
    }
    liste_print_rows(liste, i);

    liste_free_all_so_far(liste, i);

}
