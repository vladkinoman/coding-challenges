#include "isogram.h"

bool is_isogram(const char phrase[]) {
    if (!phrase) return false;
    int n = strlen(phrase);
    char phrasecpy[n];
    for (int i = 0; i < n; i++) {
        phrasecpy[i] = tolower(phrase[i]);
    }

    int aoccurences[27] = {0};

    for (int i = 0; i < n; i++) {
        if (phrasecpy[i] == ' ' || phrasecpy[i] == '-') continue;
        if (++aoccurences[phrasecpy[i] - 'a'] > 1) return false;
    }

    return true;
}