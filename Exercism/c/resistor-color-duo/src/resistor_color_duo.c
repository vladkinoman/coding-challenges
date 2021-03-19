#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t bands[]) {
    return bands[0]*10 + bands[1];
}