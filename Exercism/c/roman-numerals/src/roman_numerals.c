#include "roman_numerals.h"

char *to_roman_numeral(unsigned int number) {
    char * result = malloc(10);
    result[0] = '\0';
    if (number > 3000) return result;

    unsigned int n = number, d = 1, r = 0;
    while (n != 0) {
        r = n % 10;
        char * s = malloc(10);
        s[0] = '\0';
        switch (r * d)
        {
        case 1:
            strcpy(s, "I");
            break;
        case 2:
            strcpy(s, "II");
            break;
        case 3:
            strcpy(s, "III");
            break;
        case 4:
            strcpy(s, "IV");
            break;
        case 5:
            strcpy(s, "V");
            break;
        case 6:
            strcpy(s, "VI");
            break;
        case 7:
            strcpy(s, "VII");
            break;
        case 8:
            strcpy(s, "VIII");
            break;
        case 9:
            strcpy(s, "IX");
            break;
        case 10:
            strcpy(s, "X");
            break;
        case 20:
            strcpy(s, "XX");
            break;
        case 30:
            strcpy(s, "XXX");
            break;
        case 40:
            strcpy(s, "XL");
            break;
        case 50:
            strcpy(s, "L");
            break;
        case 60:
            strcpy(s, "LX");
            break;
        case 70:
            strcpy(s, "LXX");
            break;
        case 80:
            strcpy(s, "LXXX");
            break;
        case 90:
            strcpy(s, "XC");
            break;
        case 100:
            strcpy(s, "C");
            break;
        case 200:
            strcpy(s, "CC");
            break;
        case 300:
            strcpy(s, "CCC");
            break;
        case 400:
            strcpy(s, "CD");
            break;
        case 500:
            strcpy(s, "D");
            break;
        case 600:
            strcpy(s, "DC");
            break;
        case 700:
            strcpy(s, "DCC");
            break;
        case 800:
            strcpy(s, "DCCC");
            break;
        case 900:
            strcpy(s, "CM");
            break;
        case 1000:
            strcpy(s, "M");
            break;
        case 2000:
            strcpy(s, "MM");
            break;
        case 3000:
            strcpy(s, "MMM");
            break;
        default:
            // skip 0 and other numbers.
            break;
        }
        strcpy(result, strcat(s, result));
        free(s);
        n = n / 10;
        d *= 10;
    }
    return result;
}