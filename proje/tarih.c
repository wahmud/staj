#include "tarih.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

int is_real_date(int gun, int ay, int yil)
{
    if (gun >= 1) {
        if (ay == 1)
            return gun <= 31;
        if (ay == 2) 
            return gun <= 28 + isleap(yil);
        if (ay == 3)
            return gun <= 31;
        if (ay == 4)
            return gun <= 30;
        if (ay == 5)
            return gun <= 31;
        if (ay == 6)
            return gun <= 30;
        if (ay == 7)
            return gun <= 31;
        if (ay == 8)
            return gun <= 31;
        if (ay == 9)
            return gun <= 30;
        if (ay == 10)
            return gun <= 31;
        if (ay == 11)
            return gun <= 30;
        if (ay == 12)
            return gun <= 31;
    }
    return 0;
}

int gecerli_gun_tarihi_mi(char* tarih)
{
    if (strlen(tarih) > 10)
        return 0;
    time_t zaman;
    time(&zaman);
    struct tm* p = localtime(&zaman);
    
    int gun, ay, yil;
    int sscanf_ret1 = sscanf(tarih, "%d-%d-%d", &gun, &ay, &yil);
    if (sscanf_ret1 != 3)
        return 0;
    else if (!is_real_date(gun, ay, yil))
        return 0;
    else if (yil < 1800)
        return 0;
    else if (yil > p->tm_year + 1900)
        return 0;
    else if (yil == p->tm_year + 1900) {
        if (ay > p->tm_mon + 1)
            return 0;
        else if (ay == p->tm_mon + 1) {
            if (gun > p->tm_mday)
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
}
int gecerli_ay_tarihi_mi(char* tarih)
{
    if (strlen(tarih) > 7)
        return 0;
    time_t zaman;
    time(&zaman);
    struct tm* p = localtime(&zaman);

    int ay, yil;
    int c;
    int sscanf_ret1 = sscanf(tarih, "%d-%d", &ay, &yil);
    if (sscanf_ret1 != 2)
        return 0;
    else if (ay > 12 || ay < 1)
        return 0;
    else if (yil < 1800)
        return 0;
    else if (yil > p->tm_year + 1900)
        return 0;
    else if (yil == p->tm_year + 1900) {
        if (ay > p->tm_mon + 1)
            return 0;
        else
            return 1;
    }
    else
        return 1;

}
