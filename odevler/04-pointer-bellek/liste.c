#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define  MIN_LIST_SIZE  4
int liste_loop_asist(int i)
{
    static int is_arrived = MIN_LIST_SIZE;
    if (is_arrived - 1 == i) {
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
/////

int main(void)
{
    char** liste = (char**)malloc(sizeof(*liste) * MIN_LIST_SIZE);
    if (!liste) {
        printf("Bellek yetersiz!\n");
        return 1;
    }
    printf("Satirlari girin:\n");
    char temp_row[201];

    int i;
    for (i = 0; ; ++i) {
        char* fgets_ret = fgets(temp_row, 201, stdin);
        if (!fgets_ret) {
            printf("Dosya sonu program sonlandirildi\n");
            return 1;
        }
        size_t size = strlen(temp_row);
        if (temp_row[size - 1] != '\n')
            for (int ch1;(ch1 = getchar()) != '\n' && ch1 != EOF;);
        else
            temp_row[size - 1] = '\0';

        char* row = (char*)malloc(strlen(temp_row) + 1);
        if (!row) {
            printf("Bellek yetersiz!\n");
            return 1;
        }
        strcpy(row, temp_row);
        liste[i] = row;
        if (liste_loop_asist(i)) {
            int ch_;
            printf("Daha giris yapmak istiyor musunuz? (e/h):");
            while ((ch_ = getchar()) != 'e' && ch_ != 'h' && ch_ != EOF) {
                for (;(ch_ = getchar()) != '\n';);
                printf("Daha giris yapmak istiyor musunuz? (e/h):");
            }
            if (ch_ == 'e') {
                size_t size_representation;
                char** temp = (char**)realloc(liste, size_representation = liste_realloc_size_asist());
                if (temp) {
                    liste = temp;
                    printf("%zu adet ek satir girin:\n", size_representation / 16);
                }
                else {
                    printf("Bellek yetersiz!\n");
                    return 1;
                }
            }
            else if (ch_ == 'h') {
                ++i;                //çünkü break ile i bir artmadan çıkılacak döngüden, ve bize her çıkışta o artmış hali gerekiyor.
                break;
            }
            else {
                printf("Dosya sonu program sonlandirildi\n");
            }

            for (int ch2; (ch2 = getchar()) != '\n' && ch2 != EOF;);
        }
    }
    printf("\n%d Adet Satir Girdiniz\nIste Girdiginiz Satirlar:\n", i);

    for (int j = 0; j < i; ++j) {
        printf("%s\n", liste[j]);
    }

    for (int j = 0; j < i; ++j) {
        free(liste[j]);
    }
    free(liste);

}
