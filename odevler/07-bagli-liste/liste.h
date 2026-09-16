#ifndef LISTE_H
#define LISTE_H

#include "kayit.h"

struct Dugum { struct Kayit kayit; struct Dugum* sonraki; };

struct Dugum* dugum_ekle(struct Dugum** p_bas, struct Kayit k);
void liste_bas(struct Dugum* bas);
void liste_bosalt(struct Dugum** p_bas);

#endif