#include "darts.h"

uint8_t score(coordinate_t landing_position) {
    float x = landing_position.x;
    float y = landing_position.y;
    float r = sqrtf(x*x + y*y);
    
    if      (r <= 1.0) return 10;
    else if (r <= 5.0) return 5;
    else if (r <= 10.0) return 1;
    
    return 0;
}

