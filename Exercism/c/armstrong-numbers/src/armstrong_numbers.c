#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate) {
    int num = candidate;
    int sum = 0;
    int digits = number_of_digits(num);
    while (num != 0) {
        sum += pow(num % 10, digits);
        num /= 10;
    }
    return sum == candidate;
}

int number_of_digits(int num) {
    int n = num;
    int amount = 0;
    while (n != 0) {
        amount++;
        n /= 10;
    }
    return amount;
}
