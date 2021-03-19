#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum {
    BLACK, BROWN, RED, ORANGE, YELLOW,
    GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

extern const resistor_band_t bands[];

resistor_band_t color_code();

const resistor_band_t *colors();

#endif
