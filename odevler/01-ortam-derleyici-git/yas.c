#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int is_valid_date(int day, int mon, int year)
{
    time_t sene = time(NULL);
    struct tm* senemiz = localtime(&sene);

    if (is_real_date(day, mon, year) && (year >= 1899) && (year <= (senemiz->tm_year + 1900))) {
        if ((year == senemiz->tm_year + 1900)) {
            if (mon > senemiz->tm_mon + 1)
                return 0;
            else if (mon == senemiz->tm_mon + 1 && day > senemiz->tm_mday)
                return 0;
        }
    }
    else
        return 0;
    return 1;
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    char* week[] = {"pazar", "pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi"};

    printf("lutfen adinizi girin: ");
    char name[MAX_NAME_LEN];
    char* fgets_ret = fgets(name, MAX_NAME_LEN, stdin);
    if (!fgets_ret) {
        printf("dosya sonu program sonlandirildi.\n");
        exit(0);
}
    if (strlen(name) == 39 && name[strlen(name) - 1] != '\n')
        for (int c; ((c = getchar()) != '\n' && c != EOF););
    else 
        name[strlen(name) - 1] = '\0';

    printf("dogum tarihinizi girin (gg aa yyyy): ");
    int day;
    int mon;
    int year;

    time_t sene = time(NULL);
    struct tm* senemiz = localtime(&sene);

    while (1) {
        int scanf_cntr = scanf("%d%d%d", &day, &mon, &year);
        if (scanf_cntr == 3 && is_valid_date(day, mon, year)) {
            int week_num_of_birth = weekday(day, mon, year);
            printf("Merhaba %s! bu yil %d yasindasin ve dogdugun gun %s gunuydu.\n", name, senemiz->tm_year + 1900 - year, week[week_num_of_birth]);
            
            double age = exact_age(day, mon, year);
            printf("Ayrica tam yasin yaklasik olarak %f\n", age);
            break;
        }
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) {
                printf("dosya sonu program sonlandirildi.\n");
                exit(0);
            }
            printf("Lutfen gecerli bir tarih girin: ");
        }
    }

}