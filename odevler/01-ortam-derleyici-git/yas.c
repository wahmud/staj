#include <stdio.h>
#define   MAX_NAME_LEN   40
#define   CURRENT_YEAR   2026

int main(void)
{
    printf("lutfen adinizi girin: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    printf("dogum yilinizi girin: ");
    int date;
    scanf("%d", date);

    printf("Merhaba %s! bu yil %d yasindasin\n", name, CURRENT_YEAR - date);


    //uyarı istiyoruz:
    //int x;

}