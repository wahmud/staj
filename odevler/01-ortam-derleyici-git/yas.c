#include <stdio.h>
#include <time.h>
#define   MAX_NAME_LEN   40
#define   CURRENT_YEAR   2026
#define   isleap(x)      x%4 == 0  ?  (x%100 == 0  ?  x%400 == 0  :  1)  :  0


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
    //int days = num_of_passed_day(d, m, y);

    time_t now = time(NULL);
    struct tm* nowadate = localtime(&now);
    int year_now = (nowadate->tm_year + 1900);
    int mon_now = (nowadate->tm_mon + 1);
    int day_now = (nowadate->tm_mday);

    int num_of_days_at_year_now = num_of_days_at_certain_year(day_now, mon_now, year_now);
    int num_of_days_at_year_birth = num_of_days_at_certain_year(d, m, y);

    return ((double)year_now - (double)y) + (num_of_days_at_year_birth > num_of_days_at_year_now   ?  ((((double)365 - ((double)num_of_days_at_year_birth - (double)num_of_days_at_year_now))) / (double)365) - 1   :   (((double)num_of_days_at_year_now - (double)num_of_days_at_year_birth) / (double)365));
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
    printf("Ayrica tam yasin yaklasik olarak %f\n", age)

;
}