#include "tarih.h"

int is_real_date(int day, int mon, int year)
{
    if (day >= 1) {
        if (mon == 1)
            return day <= 31;
        if (mon == 2) 
            return day <= 28 + isleap(year);
        if (mon == 3)
            return day <= 31;
        if (mon == 4)
            return day <= 30;
        if (mon == 5)
            return day <= 31;
        if (mon == 6)
            return day <= 30;
        if (mon == 7)
            return day <= 31;
        if (mon == 8)
            return day <= 31;
        if (mon == 9)
            return day <= 30;
        if (mon == 10)
            return day <= 31;
        if (mon == 11)
            return day <= 30;
        if (mon == 12)
            return day <= 31;
    }
    return 0;
}