#include "pangram.h"

bool is_pangram(const char *sentence) {
    if (!sentence) return false;
    
    int alphabet[26] = {0};
    
    int n = strlen(sentence);
    for (int i = 0; i < n; i++) {
        if (isalpha(sentence[i])) {
            alphabet[tolower(sentence[i]) - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) return false;
    }
    return true;
}