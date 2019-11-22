#include <bits/stdc++.h>
#include <cmath>
#include <stdexcept>
using namespace std;

string pangrams(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    set<char> alphabet;
    for (auto it = s.begin();
        it != s.end(); it++) {
        if (*it != ' ') alphabet.emplace(*it);
    }
    if (alphabet.size() != 26)
        return "not pangram";
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);
    int n = s.size();
    if (n <= 0 || n > pow(10, 3))
        invalid_argument(" ");
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ' && !(s[i] >= 'A'
        && s[i] <=  'Z') && !(s[i] >= 'a'
        && s[i] <=  'z')) {
            throw invalid_argument(" ");
        }
    }
    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
