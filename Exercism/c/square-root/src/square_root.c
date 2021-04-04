#include "square_root.h"

int square_root(int natural_radicand) {
    if (natural_radicand < 1) return -1;
    // Exponential identity.
    //  The denominator in the fraction corresponds to the nth root.
    return round(exp(1.0/2.0 * log(natural_radicand)));
}