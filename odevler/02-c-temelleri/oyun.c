#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sayi_uret(void)
{
    srand(time(NULL));
    return rand() % 100 + 1;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int tahmin_al(void)
{
    int value;
    while (1) {
        int scanret = scanf("%d", &value);
        
        if (scanret == 1 && (0 < value  && value <= 100)) {
            return value;
        }
        else if (scanret == 0) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) {
                printf("\ndosya sonu program sonlandirildi.\n");
                exit(0);
            }
            printf("lutfen gecerli bir sayi girin: ");
        }
        else if (scanret == -1) {
            printf("\ndosya sonu program sonlandirildi.\n");
            exit(0);
        }
        else {
            printf("lutfen 1-100 araliginda bir sayi girin: ");
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int oyunu_oynat(int sayi)
{
    int cnt = 0;
    while (1) {
        int tahmin = tahmin_al();
        if (tahmin < sayi) {
            printf("daha buyuk bir sayi girin: ");
            ++cnt;
        }
        else if (tahmin > sayi) {
            printf("daha kucuk bir sayi girin: ");
            ++cnt;
        }
        else {
            printf("sayiyi buldun!\n");
            ++cnt;
            return cnt;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int sayi = sayi_uret();
    printf("sayiyi bulma oyunu icin 1-100 arasi bir sayi girin: ");
    int deneme = oyunu_oynat(sayi);
    printf("sayiyi %d denemede buldun.", deneme);
}



