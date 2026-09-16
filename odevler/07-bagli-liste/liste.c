#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

struct Dugum* dugum_ekle(struct Dugum** p_bas, struct Kayit k)
{
    struct Dugum dugum;
    for (;*p_bas != NULL;) {
        p_bas = &(*p_bas)->sonraki;
    }
    *p_bas = (struct Dugum*)malloc(sizeof(struct Dugum));
    if (!*p_bas)
        return NULL;
    dugum.kayit = k;
    dugum.sonraki = NULL;
    (*p_bas)->kayit = dugum.kayit;
    (*p_bas)->sonraki = dugum.sonraki;
    return *p_bas;
}

/////////////////////////////////////////////////////////////////////////////
void liste_bosalt(struct Dugum** p_bas)
{
    for (;*p_bas != NULL;){
        struct Dugum* simdiki = *p_bas;
        *p_bas = (*p_bas)->sonraki;
        free(simdiki);
    }
    *p_bas = NULL;
}

///////////////////////////////////////////////////////////////////////////////

void liste_bas(struct Dugum* bas)
{
    for (int i = 0; bas != NULL; ++i) {
        printf("\n%d. Kayit:\nAd: %s\nYas: %d\nTarih: %s\n", i + 1, bas->kayit.ad, bas->kayit.yas, bas->kayit.tarih);
        bas = bas->sonraki;
    }
}