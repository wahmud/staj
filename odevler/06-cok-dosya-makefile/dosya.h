#include "kayit.h"
#ifndef DOSYA_H
#define DOSYA_H

int kayitlari_oku(struct Kayit** p_kayitlar, int* p_kapasite);
int kayitlari_yaz(struct Kayit* kayitlar, int adet);

#endif