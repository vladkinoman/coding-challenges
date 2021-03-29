#include "grains.h"

uint64_t square(uint8_t index) {
    if (index <= 0 || index > 64) return 0;
    return 1ull << (index - 1);
}

uint64_t total(void) {
    return -1 | (1ull << 63); // -1 = ~1 + 1
}