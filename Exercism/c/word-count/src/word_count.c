#include "word_count.h"

int count_words(const char *sentence, word_count_word_t * words) {
    if (!sentence || !words) return 0;

    int n = strlen(sentence);
    char s[n+1];
    for (int i = 0; i < n; i++) {
        s[i] = tolower(sentence[i]);
    }
    s[n] = '\0';

    // Create an array with delimiters (without the ' character).
    char delimiters[100];
    int p = 0;
    // Tried ASCII table here but that didn't work.
    delimiters[p++] = ' ';  delimiters[p++] = '\n';
    delimiters[p++] = '\t'; delimiters[p++] = '\r';
    // [SPACE] follows by '!' (33th)
    for (int q = 33; q < 48; q++) {
        // Keep the ' characters until the final stage.
        if (q != '\'') delimiters[p++] = q;
    }
    // 9 follows by ':'
    for (int q = 58; q < 65; q++)   delimiters[p++] = q;
    // Z follow by '['
    for (int q = 91; q < 96; q++)   delimiters[p++] = q;
    // z follows by '{'
    for (int q = 123; q < 127; q++) delimiters[p++] = q;
    
    // Count words.
    char * t = strtok(s, delimiters);
    int uniqueWords = 0;
    do {
        if (strlen(t) > MAX_WORD_LENGTH) return EXCESSIVE_LENGTH_WORD;
        bool isFound = false;
        for (int i = 0; i < uniqueWords; i++) {
            if (strcmp(words[i].text, t) == 0) {
                words[i].count++;
                isFound = true;
            }
        }
        if (!isFound) {
            if (uniqueWords >= MAX_WORDS) return EXCESSIVE_NUMBER_OF_WORDS;
            words[uniqueWords].count = 1;
            strcpy(words[uniqueWords++].text, t);
        }
    } while ((t = strtok(NULL, delimiters)));
    
    // Remove the preceding and following ' characters.
    for (int i = 0; i < uniqueWords; i++) {
        int wordLength = strlen(words[i].text);
        if (words[i].text[0] == '\'' || words[i].text[wordLength-1] == '\'') {
            if (words[i].text[0] == '\'') {
                strcpy(words[i].text, strchr(words[i].text, '\'') + 1);
                --wordLength;
            }
            if (words[i].text[wordLength-1] == '\'') {
                words[i].text[wordLength-1] = '\0';
            }
            // Check for the duplicates and remove them.
            for (int j = 0; j < uniqueWords; j++) {
                if (i == j) continue;
                if (strcmp(words[i].text, words[j].text) == 0) {
                    int whereToDelete = i < j ? j : i;
                    int whereToAdd    = i < j ? i : j;
                    words[whereToAdd].count += words[whereToDelete].count;
                    // Shift the remaining words to the left.
                    for (int k = whereToDelete; k < uniqueWords-1; k++) {
                        words[k] = words[k+1];
                    }
                    words[uniqueWords-1].count   = 0;
                    words[uniqueWords-1].text[0] = '\0';
                    --uniqueWords;
                    break;
                }
            }
        }
    }
    
    return uniqueWords;
}