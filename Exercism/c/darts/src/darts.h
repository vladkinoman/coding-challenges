#ifndef DARTS_H
#define DARTS_H
#include <stdint.h>
#include <math.h>

typedef struct coordinate_t { float x, y; } coordinate_t;

uint8_t score(coordinate_t landing_position);

#endif
