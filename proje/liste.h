#ifndef LISTE_H
#define LISTE_H
#include "harcama.h"

struct Harcamalar* dugum_ekle_har(struct Harcamalar**, char* harcamalar);
struct Kategoriler* dugum_ekle_kat(struct Kategoriler**, struct Kategoriler);
void liste_bosalt_har(struct Harcamalar**);
void liste_bosalt_kat(struct Kategoriler**);
void liste_sirala_har(struct Harcamalar**);
void liste_sirala_kat(struct Kategoriler**);
struct Kategoriler* liste_ara(struct Kategoriler* bas, char* ad);
#endif