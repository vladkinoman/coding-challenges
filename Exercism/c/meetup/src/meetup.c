#include "meetup.h"

int meetup_day_of_month(unsigned int year, unsigned int month, 
    const char *week, const char *day_of_week) {
    
    int is_teenth = 0, which_day = 0;
    if (strcmp(week, "teenth") == 0) is_teenth++;
    
    if (strcmp(week, "first") == 0) {
        which_day = 1;
    } else if (strcmp(week, "second") == 0) {
        which_day = 2;
    } else if (strcmp(week, "third") == 0) {
        which_day = 3;
    } else if (strcmp(week, "fourth") == 0) {
        which_day = 4;
    } else if (strcmp(week, "fifth") == 0) {
        which_day = 5;
    } else if (strcmp(week, "last") == 0) {
        which_day = -1;
    }

    // Too repetetive:
    int day;
    if        (strcmp(day_of_week, "Monday") == 0) {
        day = 1;
    } else if (strcmp(day_of_week, "Tuesday") == 0) {
        day = 2;
    } else if (strcmp(day_of_week, "Wednesday") == 0) {
        day = 3;
    } else if (strcmp(day_of_week, "Thursday") == 0) {
        day = 4;
    } else if (strcmp(day_of_week, "Friday") == 0) {
        day = 5;
    } else if (strcmp(day_of_week, "Saturday") == 0) {
        day = 6;
    } else {
        day = 0;
    }
    struct tm time_str;
    time_str.tm_year = year - 1900;
    time_str.tm_mon = month - 1;
    if (which_day == -1) time_str.tm_mday = 31; // possible bug
    else time_str.tm_mday = 1; // We start from the first day of the month
    time_str.tm_hour = 0;
    time_str.tm_min = 0;
    time_str.tm_sec = 1;
    time_str.tm_isdst = -1;
    time_str.tm_wday = day;
    time_t t = mktime(&time_str);
    printf("%s", ctime(&t));
    if (time_str.tm_mon != month - 1) {
        time_str.tm_mday = 30;
        time_str.tm_year = year - 1900;
        time_str.tm_mon = month - 1;
        time_str.tm_hour = 0;
        time_str.tm_min = 0;
        time_str.tm_sec = 1;
        time_str.tm_isdst = -1;
        time_str.tm_wday = day;
        t = mktime(&time_str);
        if (time_str.tm_mon != month - 1) {
            time_str.tm_mday = 29;
            time_str.tm_year = year - 1900;
            time_str.tm_mon = month - 1;
            time_str.tm_hour = 0;
            time_str.tm_min = 0;
            time_str.tm_sec = 1;
            time_str.tm_isdst = -1;
            time_str.tm_wday = day;
            t = mktime(&time_str);
            if (time_str.tm_mon != month - 1) {
                time_str.tm_mday = 28;
                time_str.tm_year = year - 1900;
                time_str.tm_mon = month - 1;
                time_str.tm_hour = 0;
                time_str.tm_min = 0;
                time_str.tm_sec = 1;
                time_str.tm_isdst = -1;
                time_str.tm_wday = day;
                t = mktime(&time_str);
            }
        }
    }
        

    int day_counter = time_str.tm_mday;
    if (which_day == -1) {
        for (int i = time_str.tm_wday; day_counter > 0; --i, --day_counter) {
            if (i == -1) i = 6;
            if (i == day) return day_counter;
        }
    }
    int encounters = 0;
    for (int i = time_str.tm_wday; day_counter < 32; i++, day_counter++) {
        if (i == 7) i = 0;
        if (is_teenth && i == day && day_counter >= 13 && day_counter <= 19) {
            break;
        }
        if (which_day && i == day) {
            encounters++;
            if (encounters == which_day) break;
        }
    }
    return day_counter;
}