#include "roman_numerals.h"

char *to_roman_numeral(unsigned int number) {
    unsigned int n = number;
    char * result = malloc(10);
    result[0] = '\0';
    if (n == 1) strcat(result, "I");
    if (n == 2) strcat(result, "II");
    if (n == 3) strcat(result, "III");
    if (n == 4) strcat(result, "IV");
    if (n == 5) strcat(result, "V");
    if (n == 6) strcat(result, "VI");
    if (n == 7) strcat(result, "VII");
    if (n == 8) strcat(result, "VIII");
    if (n == 9) strcat(result, "IX");
    if (n == 10) strcat(result, "X");
    if (n == 50) strcat(result, "L");
    if (n == 100) strcat(result, "C");
    if (n == 500) strcat(result, "D");
    if (n == 1000) strcat(result, "M");
    
    return result;
}