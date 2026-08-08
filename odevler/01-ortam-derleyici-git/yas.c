#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define   MAX_NAME_LEN   40
#define   CURRENT_YEAR   2026
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

    printf("days_now = %d\n", days_now);
    printf("days_at_birth = %d\n", days_at_birth);
    
    double flag = 0;
    if ((mon_now > 2 && m > 2)) {
        if (isleap(year_now) && !isleap(y)) {
            days_at_birth++;
            flag = 1.0;
            printf("flag1 = %f\n", flag);
        }
        else if (!isleap(year_now) && isleap(y)) {
            days_now++;
            flag = 1.0;
            printf("flag2 = %f\n", flag);
        }
        else if (isleap(year_now) && isleap(y)) {
            flag = 1.0;
            printf("flag3 = %f\n", flag);
        }
    }
    else if (mon_now <= 2 && m <= 2) {
        if (isleap(year_now) || isleap(y)) {
            flag = 1.0;
            printf("flag4 = %f\n", flag);
        }
    }
    else if (mon_now <= 2 || m <= 2) {
        if (m > 2 && isleap(year_now) && !isleap(y)) {
            days_at_birth++;
            flag = 1.0;
            printf("flag5 = %f\n", flag);
        }
        else if (m > 2 && isleap(year_now) && isleap(y)) {
            flag = 1.0;
            printf("flag6 = %f\n", flag);
        }
        else if (mon_now > 2 && isleap(y) && !isleap(year_now)) {
            days_now++;
            flag = 1.0;
            printf("flag7 = %f\n", flag);
        }
        else if (mon_now > 2 && isleap(y) && isleap(year_now)) {
            flag = 1.0;
            printf("flag8 = %f\n", flag);
        }
    }

    printf("days_now = %d\n", days_now);
    printf("days_at_birth = %d\n", days_at_birth);

    printf("flag_bef_cal = %f\n", flag);

    if (days_at_birth > days_now) {
        return (year_now - (double)y)    +    ((double)days_now - (double)days_at_birth) / (365.0 + flag);
    }
    else {
        return (year_now - (double)y)    +    ((double)days_now - (double)days_at_birth) / (365.0 + flag);
    }
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

    printf("Merhaba %s! bu yil %d yasindasin ve dogdugun gun %s gunuydu.\n", name, CURRENT_YEAR - year, week[week_num_of_birth]);

    double age = exact_age(day, mon, year);
    printf("Ayrica tam yasin yaklasik olarak %f\n", age);


}