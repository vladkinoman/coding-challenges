#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int n = 0;
    if ((n = strlen(lhs)) != (int) strlen(rhs)) return -1;
    int hamming_distance = 0;
    for (int i = 0; i < n; i++) {
        if (lhs[i] != rhs[i]) hamming_distance++;
    }
    return hamming_distance;
}