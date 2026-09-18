#ifndef LISTE_H
#define LISTE_H

#include "kayit.h"

struct Dugum { struct Kayit kayit; struct Dugum* sonraki; };

struct Dugum* dugum_ekle(struct Dugum** p_bas, struct Kayit k);
void liste_bas(struct Dugum* bas);
void liste_bosalt(struct Dugum** p_bas);
struct Dugum* liste_ara(struct Dugum* bas, const char* ad); //Adı verilen kaydı bulursa o düğümün adresini döndürsün, bulamazsa NULL döndürsün

#endif