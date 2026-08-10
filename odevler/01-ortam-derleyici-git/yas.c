#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define   MAX_NAME_LEN   40
#define   isleap(x)      (x%4 == 0  ?  (x%100 == 0  ?  x%400 == 0  :  1)  :  0)


int weekday(int d, int m, int y)
{
    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 1, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int num_of_days_at_certain_year(int d, int m, int y)
{
    static const int mon_days[][12] = {{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, 
                                       {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},};
    return mon_days[isleap(y)][m - 1] + d;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

double exact_age(int d, int m, int y)
{
    time_t now = time(NULL);
    struct tm* nowadate = localtime(&now);
    int year_now = (nowadate->tm_year + 1900);
    int mon_now = (nowadate->tm_mon + 1);
    int day_now = (nowadate->tm_mday);

    int days_now = num_of_days_at_certain_year(day_now , mon_now, year_now);
    int days_at_birth = num_of_days_at_certain_year(d, m, y);

    double flag = 0;
    if ((mon_now > 2 && m > 2)) {
        if (isleap(year_now) && !isleap(y)) {
            days_at_birth++;
            flag = 1.0;
        }
        else if (!isleap(year_now) && isleap(y)) {
            days_now++;
            flag = 1.0;
        }
        else if (isleap(year_now) && isleap(y)) {
            flag = 1.0;
        }
    }
    else if (mon_now <= 2 && m <= 2) {
        if (isleap(year_now) || isleap(y)) {
            flag = 1.0;
        }
    }
    else if (mon_now <= 2 || m <= 2) {
        if (m > 2 && isleap(year_now) && !isleap(y)) {
            days_at_birth++;
            flag = 1.0;
        }
        else if (m > 2 && isleap(year_now) && isleap(y)) {
            flag = 1.0;
        }
        else if (mon_now > 2 && isleap(y) && !isleap(year_now)) {
            days_now++;
            flag = 1.0;
        }
        else if (mon_now > 2 && isleap(y) && isleap(year_now)) {
            flag = 1.0;
        }
    }

    return (year_now - (double)y)    +    ((double)days_now - (double)days_at_birth) / (365.0 + flag);
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


int main(void)
{
    char* week[] = {"pazar", "pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi"};
    
    printf("lutfen adinizi girin: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    printf("dogum tarihinizi girin (gg aa yyyy): ");
    int day;
    int mon;
    int year;
    scanf("%d%d%d", &day, &mon, &year);

    int week_num_of_birth = weekday(day, mon, year);
    time_t sene = time(NULL);
    struct tm* senemiz = localtime(&sene);
    printf("Merhaba %s! bu yil %d yasindasin ve dogdugun gun %s gunuydu.\n", name, senemiz->tm_year + 1900 - year, week[week_num_of_birth]);

    double age = exact_age(day, mon, year);
    printf("Ayrica tam yasin yaklasik olarak %f\n", age);


}