#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

double std_dev(vector<int> x) {
    int N = x.size();
    int mean_sum = 0;
    for (int i = 0; i < N; i++) {
        mean_sum += x[i];
    }
    double mean = mean_sum / N;
    double variance_sum = 0;
    for (int i = 0; i < N; i++) {
        variance_sum += (x[i]- mean) 
        * (x[i]- mean);
    }
    return sqrt(variance_sum / N);
}

int main() {
    int N = 0;
    cin >> N;
    if (N < 5 || N > 100)
        invalid_argument("");
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        if (x[i] <= 0 || x[i] > pow(10, 5))
            invalid_argument("");
    }
    cin.precision(1);
    cout << fixed <<std_dev(x) << endl;
    return 0;
}
