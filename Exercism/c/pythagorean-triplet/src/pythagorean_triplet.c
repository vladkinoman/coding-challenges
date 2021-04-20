#include "pythagorean_triplet.h"

triplets_t * triplets_with_sum(uint16_t sum) {
    triplets_t * triplets = malloc(sizeof(triplets_t));
    triplets->triplets = malloc(sizeof(triplet_t));
    triplets->count = 0;
    for (uint16_t i = 1; i < sum; i++) {
        for (uint16_t j = i+1; j < sum; j++) {
            double d = sqrt(i*i + j*j);
            if ((int)d != d) continue;
            uint16_t k = (uint16_t) d;
            if (i + j + k == sum) {
                triplets->triplets[triplets->count].a = i;
                triplets->triplets[triplets->count].b = j;
                triplets->triplets[triplets->count].c = k;
                triplets->count++;
            }
        }
    }
    return triplets;
}

void free_triplets(triplets_t * triplets) {
    free(triplets->triplets);
    free(triplets);
}