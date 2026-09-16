#include <string.h>
#include <stdio.h>
#include "kayit.h"

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
