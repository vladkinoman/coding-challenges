#include "anagram.h"

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for subject. Contents of candidate structures may be modified.
 */
void find_anagrams(const char *subject, struct candidates *candidates) {
    size_t n_subject = strlen(subject);
    
    for (size_t i = 0; i < candidates->count; i++) {

        size_t n_candidate = strlen(candidates->candidate[i].word);
        if (n_subject != n_candidate) {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
        }

        if (strcmp(subject, candidates->candidate[i].word) == 0) {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            continue;
        }
        
        int a[n_subject];
        memset(a, 0, n_subject*sizeof(int) );
        int b[n_candidate];
        memset(b, 0, n_candidate*sizeof(int) );
        
        for (size_t j = 0; j < n_subject; j++) {
            for (size_t k = 0; k < n_candidate; k++) {
                if (subject[j] == candidates->candidate[i].word[k] && b[k] == 0) {
                    a[j]++;
                    b[k]++;
                    break;
                }
            }
        }
        
        for (size_t j = 0; j < n_subject; j++) {
            if (a[j] == 0) {
                candidates->candidate[i].is_anagram = NOT_ANAGRAM;
                break;
            }
        }
        if (candidates->candidate[i].is_anagram == UNCHECKED) {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
        }
    }
}