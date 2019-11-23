#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the decentNumber function below.
void decentNumber(int n) {
    long number = 0;
    long j = 1L;
    for (int i = 0; i < n; i++, j*=10) {
        number += 5L * j;
    }
    int number_of_5s = n;
    int number_of_3s = 0;
    j = 1L;
    for (int i = 0; i <= n; i++, j*=10) {
        if ((number_of_5s % 3 == 0 && number_of_3s == 0)
        || (number_of_5s % 3 == 0 && number_of_3s % 5 == 0)
        || (number_of_5s == 0 && number_of_3s % 5 == 0)) {
            cout << number << endl;
            return;
        } else {
            number -= 5L * j;
            number += 3L * j;
            --number_of_5s;
            number_of_3s++;
        }
    }
    cout << -1 << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));
    if (t < 1 || t > 20)
        throw invalid_argument(" ");
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));
        if (n < 1 || n > 100000)
            throw invalid_argument(" ");
        decentNumber(n);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
