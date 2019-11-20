#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

double interquartile_range(vector<int> x, vector<int> f, int f_sum) {
    int n = f_sum;
    vector<int> s(n);
    for (int i = 0, j = 0, k = 0;
     i < n; i++) {
        s[i] = x[j];
        if (k < f[j] - 1) k++;
        else {
            j++;
            k = 0;
        }
    }
    sort(s.begin(), s.end());
    double q1 = 0;
    double q3 = 0;
    int mid = (n - 1) / 2;
    if (n % 2 != 0) --mid;
    if (mid % 2 == 0) {
        q1 = s[mid/2];
    } else {
        q1 = (s[mid/2]+s[mid/2+1])/2;
    }
    
    if (n % 2 != 0) mid++;
    if ((mid + n) % 2 == 0) {
        q3 = s[(mid+n)/2];
    } else {
        q3 = (s[(mid+n)/2] 
        + s[(mid + n)/2+1])/2;
    }
    
    return round(abs(q3 - q1) * 10) / 10;
}

int main() {
    int n = 0;
    cin >> n;
    if (n < 5 || n > 50)
        invalid_argument("");
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] <= 0 || x[i] > 100)
            invalid_argument("");
    }
    vector<int> f(n);
    int f_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >>f[i];
        f_sum += f[i];
    }
    if (f_sum <= 0 || f_sum > pow(10, 3))
        invalid_argument("");
    cout.precision(1);
    cout << fixed << interquartile_range(x, f, f_sum) << endl;
    return 0;
}
