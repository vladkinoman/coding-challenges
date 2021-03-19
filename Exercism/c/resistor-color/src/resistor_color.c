#include "resistor_color.h"

resistor_band_t color_code(resistor_band_t band) {
    return band;
}

const resistor_band_t *colors() {
    return bands;
}

const resistor_band_t bands[] = {BLACK, BROWN, RED, ORANGE, YELLOW,
    GREEN, BLUE, VIOLET, GREY, WHITE};