#include "series.h"

slices_t slices(char *input_text, unsigned int substring_length) {
    unsigned int string_length = strlen(input_text);
    unsigned int num_of_slices = substring_length != 0 ? 
     string_length - substring_length + 1 : substring_length;

    slices_t * slices = malloc (sizeof *slices);
    slices->substring = (char **) calloc(num_of_slices, sizeof(char*));
    slices->substring_count = 0;
    for (unsigned int i = 0; i < num_of_slices; i++) {
        // calloc is the best choice here because it initialize the space with zeros,
        // which is good because we can't terminate the string with zeroes later.
        // You will get a double free or corruption error (here or in the test_solution function).

        // Also, notice that calloc (same as malloc) can accept 0 as the first argument. 
        // Result is implementation defined.
        // > C11: 7.22.3 Memory management functions:
        //  [...] If the size of the space requested is zero, the behavior is implementation-defined: 
        //  either a null pointer is returned, or the behavior is as if the size were some nonzero value,
        //  except that the returned pointer shall not be used to access an object.
        // So, calloc may return a null pointer for an allocation of zero bytes 
        // and passing a null pointer to memcpy is undefined behavior (even if ìts third argument is 0).
        // Source: https://stackoverflow.com/questions/24727128/using-malloc0-and-memcpy.

        slices->substring[i] = (char *) calloc(substring_length + 1, sizeof(char));
    }

    for (unsigned int i = 0; i < num_of_slices; i++) {
        memcpy((void *) slices->substring[i], (void *) (input_text + i),
         substring_length);
        slices->substring_count++;
    }
    return *slices;
}
