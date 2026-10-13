#ifndef TARIH_H
#define TARIH_H

#define  isleap(x)  (x%4 == 0  ?  (x%100 == 0  ?  x%400 == 0  :  1)  :  0)
int is_real_date(int gun, int ay, int yil);
int gecerli_gun_tarihi_mi(char* tarih);
int gecerli_ay_tarihi_mi(char* tarih);
#endif