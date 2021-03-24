#include "gigasecond.h"

time_t gigasecond_after(time_t constructed_date) {
    return GIGASECOND + constructed_date;
}