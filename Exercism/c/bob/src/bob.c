#include "bob.h"

char *hey_bob(char *greeting) {

    int n = strlen(greeting);
    int amount_of_lowers  = 0;
    int amount_of_letters = 0;
    int amount_of_spaces  = 0;
    for (int i = 0; i < n; i++) {
        if (islower(greeting[i])) amount_of_lowers++;
        if (isalpha(greeting[i])) amount_of_letters++;
        if (isspace(greeting[i])) amount_of_spaces++;
    }

    bool question_mark_was_found_first = false;
    for (int i = n - 1; i >= 0; --i) {
        if (greeting[i] == '?') {
            question_mark_was_found_first = true;
            break;
        } else if (isalnum(greeting[i])) {
            break;
        }
        // Skip spaces.
    }

    if (amount_of_lowers == 0 && amount_of_letters != 0) {
        if (question_mark_was_found_first) {
            return "Calm down, I know what I'm doing!";
        } else {
            return "Whoa, chill out!";
        }
    } else {
        if (question_mark_was_found_first) {
            return "Sure.";
        } else if (amount_of_spaces == n) {
            return "Fine. Be that way!";
        }
    }

    return "Whatever.";
}