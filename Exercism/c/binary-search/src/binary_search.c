#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length) {
    int lo = 0;
    int hi = length-1;

    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if      (value < arr[mid])  hi = mid-1;
        else if (value > arr[mid])  lo = mid+1;
        else                        return (int*) &arr[mid];
    }
    
    return NULL;
}