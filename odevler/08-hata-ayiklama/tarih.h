#ifndef TARIH_H
#define TARIH_H

#define  isleap(x)  (x%4 == 0  ?  (x%100 == 0  ?  x%400 == 0  :  1)  :  0)
int is_real_date(int day, int mon, int year);

#endif