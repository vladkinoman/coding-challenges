#include "series.h"

slices_t slices(char *input_text, unsigned int substring_length) {
    unsigned int string_length = strlen(input_text);
    unsigned int num_of_slices = substring_length != 0 ? 
     string_length - substring_length + 1 : substring_length;

    slices_t * slices = malloc(sizeof *slices);
    slices->substring = (char **) calloc(num_of_slices, sizeof(char*));
    slices->substring_count = 0;
    for (unsigned int i = 0; i < num_of_slices; i++) {
        // calloc is the best choice here because it initialize the space with zeros,
        // which is good because we can't terminate the string with zeroes later.
        // you will get a double free or corruption error (here or in the test_solution function).
        slices->substring[i] = (char *) calloc(0, sizeof(char));
    }
    
    for (unsigned int i = 0; i < num_of_slices; i++) {
        memcpy((void *) slices->substring[i], (void *) (input_text + i),
         substring_length);
        slices->substring_count++;
    }
    return *slices;
}