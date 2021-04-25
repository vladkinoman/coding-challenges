#include "series.h"

slices_t slices(char *input_text, unsigned int substring_length) {
    unsigned int string_length = strlen(input_text);

    slices_t * slices = malloc(sizeof(slices_t));
    slices->substring = malloc(string_length/substring_length);
    for (int i = 0; i < MAX_SERIES_RESULTS; i++) {
        slices->substring[i] = malloc(substring_length+1);
    }
    
    slices->substring_count = 0;

    
    for (unsigned int i = 0; i + substring_length - 1 < string_length; i++) {
        strncat(slices->substring[slices->substring_count], input_text + i,
         substring_length);
        slices->substring[slices->substring_count++][substring_length] = '\0';
    }

    return *slices;
}