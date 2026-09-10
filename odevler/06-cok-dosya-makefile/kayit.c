#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kayit.h"
void* kayit_realloc(struct Kayit** p, int size)
{
    void* temp = realloc(*p, size * sizeof(**p));
    if (temp) {
        *p = temp;
        printf("Bellek alani %d adet kayita yukseltildi.\n", size);
        return temp;
    }
    else
        return temp;
}
//////////////////////////////////////////////////////////////////////////////////////
char* kayit_fgets(char* temp, int size)
{
    char* fgets_ret = fgets(temp, size, stdin);
    if (!fgets_ret)
        return fgets_ret;
    if (temp[strlen(temp) - 1] != '\n')
        for (int ch; (ch = getchar()) != '\n' && ch != EOF;);
    else
        temp[strlen(temp) - 1] = '\0';
    return temp;    
}
