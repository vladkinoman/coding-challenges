#include "rna_transcription.h"

char *to_rna(const char *dna) {
    if (!dna) return NULL;
    int n = strlen(dna);
    char * rna = malloc(n+1);
    for (int i = 0; i < n; i++) {
        switch (dna[i])
        {
        case 'G':
            rna[i] = 'C';
            break;
        case 'C':
            rna[i] = 'G';
            break;
        case 'T':
            rna[i] = 'A';
            break;
        case 'A':
            rna[i] = 'U';
            break;
        default:
            rna[i] = dna[i];
            break;
        }
    }
    rna[n] = '\0';
    return rna;
}