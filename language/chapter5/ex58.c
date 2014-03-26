/*
 * exercise 5-8
 * error checking to day_of_year and month_day
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void) {
    int month, day, yearday;
    
    yearday = day_of_year(2014, 3, 25);
    printf ("%d\n", yearday);
    month_day(2014, yearday, &month, &day);
    printf ("%d %d\n", month, day);

    return 0;
}

int day_of_year(int year, int month, int day) {
    int i, leap;
    if (year < 0) {
        return -1;
    }
    leap = year%4 == 0 && (year%100 != 0 || year%400 == 0);

    if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month]) {
        return -1;
    }

    for (i=1; i<month; i++) {
        day += daytab[leap][i];
    }
    return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && (year%100 != 0 || year%400 == 0);

    for (i=1; yearday>daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;

    if (*pday < 1 || *pday > daytab[leap][i]) {
        *pmonth = 0;
        *pday = 0;
    }
}
