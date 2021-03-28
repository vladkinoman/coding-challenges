#include "meetup.h"

struct tm init_time_str(unsigned int year, unsigned int month,
        unsigned int day, unsigned mday);

int meetup_day_of_month(unsigned int year, unsigned int month, 
        const char *week, const char *day_of_week) {
    if (!week || !day_of_week) return 0;
    
    
    #define LOOP(char_a_p, char_a_q, var) \
        for (int i = 0; i < 7; i++) {\
            if (!strcmp(char_a_p, char_a_q[var = i])) break;\
        }

    int which_mday = 0;
    char * weeks[] = {"first"/*0*/, "second", "third", "fourth",
        "fifth", "teenth"/*5*/, "last"/*6*/};
    LOOP(week, weeks, which_mday);

    int day = 0;
    char * days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};
    LOOP(day_of_week, days_of_week, day);
    #undef LOOP


    struct tm time_str;
    #define IS_MONTH_WRONG time_str.tm_mon != month - 1
    #define INIT_TS(day) time_str = init_time_str(year, month, day, day);
    // 6 corresponds to "last"
    if (which_mday == 6) {
        INIT_TS(31);
        if (IS_MONTH_WRONG) {
            INIT_TS(30);
            if (IS_MONTH_WRONG) {
                INIT_TS(29);
                if (IS_MONTH_WRONG) {
                    INIT_TS(28);
                }
            }
        }
    } else {
        INIT_TS(1);
    }
    #undef IS_MONTH_WRONG
    #undef INIT_TS


    int day_counter = time_str.tm_mday;
    if (which_mday == 6) {
        for (int i = time_str.tm_wday; day_counter > 0; --i, --day_counter) {
            if (i == -1)  i = 6;
            if (i == day) break; // Found last day.
        }
    } else {
        int encounters = 0;
        for (int i = time_str.tm_wday; day_counter < 32; i++, day_counter++) {
            if (i == 7) i = 0;
            // 5 corresponds to "teenth"
            if (which_mday == 5 && i == day && day_counter >= 13 && day_counter <= 19) {
                break; // Found teenth day.
            }
            if (which_mday < 5 && i == day) {
                // +1 - remember the weeks array
                if (++encounters == which_mday+1) break;
            }
        }
    }
    
    return day_counter;
}

struct tm init_time_str(unsigned int year, unsigned int month,
        unsigned int day, unsigned mday) {
    struct tm time_str;
    time_str.tm_year = year - 1900;
    time_str.tm_mon = month - 1;
    time_str.tm_mday = mday;
    time_str.tm_hour = 0;
    time_str.tm_min = 0;
    time_str.tm_sec = 1;
    time_str.tm_isdst = -1;
    time_str.tm_wday = day;
    mktime(&time_str);
    return time_str; 
}