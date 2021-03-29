#include "nucleotide_count.h"

char *count(const char *dna_strand) {
    // error
    if (!dna_strand) return calloc(1, 1);
    
    int n = strlen(dna_strand);
    int nucleotide_count[4] = {0};
    for (int i = 0; i < n; i++) {
        switch (dna_strand[i])
        {
        case 'A':
            nucleotide_count[0]++;
            break;
        case 'C':
            nucleotide_count[1]++;
            break;
        case 'G':
            nucleotide_count[2]++;
            break;
        case 'T':
            nucleotide_count[3]++;
            break;
        default:
            // error
            return calloc(1, 1);
        }
    }

    char * result = malloc(20 + n);
    sprintf(result, "A:%d C:%d G:%d T:%d", nucleotide_count[0], 
        nucleotide_count[1], nucleotide_count[2], nucleotide_count[3]);
    return result;
}