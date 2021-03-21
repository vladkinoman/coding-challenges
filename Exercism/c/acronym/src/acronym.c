#include "acronym.h"

char *abbreviate(const char *phrase) {
    if (!phrase || strcmp(phrase, "") == 0) return NULL;
    char * phrase_copy = malloc(strlen(phrase));
    // We can't work with a constant char array.
    strcpy(phrase_copy, phrase);
    const char delimeters[] = " ,-._"; 
    
    int n = 0;
    int size = 5;
    char *s = malloc(size);
    char *t = strtok(phrase_copy, delimeters);
    do {
        // When we allocated not enough memory.
        if (n == size - 1) {
            char * new_s = malloc(size*2);
            strcpy(new_s, s);
            free(s);
            s = new_s;
            size *= 2;
        }
        s[n++] = toupper(t[0]);
    } while((t = strtok(NULL, delimeters)) != NULL);
    // Don't forget to add a terminating character!
    s[n] = '\0';
    return s;
}