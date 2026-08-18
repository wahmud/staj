#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("%s\n", metin);

}