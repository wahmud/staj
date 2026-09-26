#include "liste.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Dugum* dugum_ekle(struct Dugum** p_bas, struct Kayit k)
{
    struct Dugum dugum;
    for (int i = 0;*p_bas != NULL; ++i) {
        //printf("%d\n", i + 1);
        p_bas = &(*p_bas)->sonraki;
    }
    //printf("bitti\n");
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
}

///////////////////////////////////////////////////////////////////////////////

void liste_bas(struct Dugum* bas)
{
    for (int i = 0; bas != NULL; ++i) {
        printf("\n%d. Kayit:\nAd: %s\nYas: %d\nTarih: %s\n", i + 1, bas->kayit.ad, bas->kayit.yas, bas->kayit.tarih);
        bas = bas->sonraki;
    }
}

///////////////////////////////////////////////////////////////////////////////

struct Dugum* liste_ara(struct Dugum* bas, const char* ad)
{
    for (; bas != NULL;) {
        if (!strcmp(ad, bas->kayit.ad)) {
            return bas;
        }
        else
        bas = bas->sonraki;
    }
    return NULL;
}

///////////////////////////////////////////////////////////////////////////////

int liste_sil(struct Dugum** p_bas, const char* ad)
{
    if (*p_bas == NULL) {
        return 1;
    }
    if (!strcmp((*p_bas)->kayit.ad, ad)) {
        struct Dugum* ilk_dugum = *p_bas;
        *p_bas = (*p_bas)->sonraki;
        free(ilk_dugum);
        return 0;
    }

    struct Dugum* onceki = *p_bas;
    struct Dugum* simdiki = *p_bas;
    for (; simdiki != NULL;) {
        if (!strcmp(simdiki->kayit.ad, ad)) {  //bir kez buraya girmeme garantisi var, eğer program for'a ulaşmışsa
            onceki->sonraki = simdiki->sonraki;
            free(simdiki);
            return 0;
        }
        else {   //for'a ulaşırsa şu garanti: bir kez else'e girecek
            onceki = simdiki;
            simdiki = simdiki->sonraki;
        }
    }
    return 1;
}
