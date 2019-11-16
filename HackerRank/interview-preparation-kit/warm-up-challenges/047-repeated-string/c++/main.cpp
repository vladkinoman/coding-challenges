#include <bits/stdc++.h>
#include <cmath>
#include <stdexcept>

using namespace std;

long repeatedString(string s, long n) {
    long nOfS = s.size();
    if (nOfS < 1 || nOfS > 100)
        invalid_argument("");
    if (n < 1 || pow(10, 12))
        invalid_argument("");
    
    long numOfALettersInS = 0;
    for (int i = 0; i < nOfS; i++) {
        if (s[i] == 'a')
            numOfALettersInS++;
    }
    
    long x = n % nOfS;
    long numOfALettersInFirstX = 0;
    for (int i = 0; i < x; i++) {
        if (s[i] == 'a')
            numOfALettersInFirstX++;
    }

    return numOfALettersInS * (n / nOfS) 
    + numOfALettersInFirstX;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
