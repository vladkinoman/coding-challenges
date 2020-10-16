#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string s_hr = "hackerrank";
    string::size_type count = 0;
    string::iterator it = s.begin()-1;
    // use string::size_type to avoid warning
    for (string::size_type i = 0; i < s_hr.size(); i++) {
        it = find(it+1, s.end(), s_hr[i]);
        if (it != s.end()) count++;
        else break;
        if (count == s_hr.size()) return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
