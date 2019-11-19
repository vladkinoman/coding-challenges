#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int nums[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            // In ASCII code, the numbers start from 48.
            nums[(int) s[i] - 48]++;
    }

    for (int i = 0; i < 10; i++) {
        cout << i << " " << nums[i] << endl;        
    }
}
