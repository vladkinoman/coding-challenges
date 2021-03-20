#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t colors[]) {
    int potential_value = (colors[0]*10+colors[1]) * (int)pow(10, colors[2]);
    resistor_value_t actual;
    actual.unit = OHMS;
    if (potential_value % 1000 == 0) {
        potential_value /= 1000;
        actual.unit = KILOOHMS;
    }
    actual.value = potential_value;
    return actual;
}