#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string hr_s = "hackerrank";
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        auto it = find(hr_s.begin()+count, hr_s.end(), s[i]);
        if (it != hr_s.end()) count++;
        if (count == hr_s.size()) return "YES";
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
