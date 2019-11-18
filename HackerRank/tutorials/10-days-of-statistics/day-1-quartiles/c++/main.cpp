#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 5 || n > 50)
        invalid_argument("n is wrong");
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] <= 0 || x[i] > 100)
            invalid_argument("x[i] is wrong");    
    }

    sort(x.begin(), x.end());
    
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    int mid = (n - 1) / 2;
    if (n % 2 == 0) {
        q2 = (x[mid] + x[mid+1]) / 2;
    } else {
        q2 = x[mid];
        --mid;
    }

    if (mid % 2 == 0) {
        q1 = x[mid / 2];
    } else {
        q1 = (x[mid / 2] 
        + x[mid/2 + 1]) / 2; 
    }

    if (n % 2 != 0) mid++;
    if ((mid + n) % 2 == 0) {
        q3 = x[(mid + n) / 2];
    } else {
        q3 = (x[(mid + n) / 2] 
        + x[(mid + n) /2 + 1]) / 2;
    }
    
    cout << q1 << endl;
    cout << q2 << endl;
    cout << q3 << endl;
    return 0;
}
