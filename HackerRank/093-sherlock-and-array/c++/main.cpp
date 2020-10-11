#include <bits/stdc++.h>
#include <numeric>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string is_pivot_found(vector<int> arr, int n, int h) {
    while (h >= 1) {
        for (int i = 1; i < n-1; i+=h) {
            int sum_left = 0, sum_right = 0;
            sum_left  = accumulate(arr.begin(),     arr.begin()+i,   0);
            sum_right = accumulate(arr.begin()+i+1, arr.begin()+n,   0);
            if (sum_left == sum_right) return "YES";
        }
        h /= 3;
    }
    return "NO";
}
// Complete the balancedSums function below.
string balancedSums(vector<int> arr) {
    int n = arr.size();
    // checking the leftmost and the rightmost elements
    if (0 == accumulate(arr.begin()+1, arr.begin()+n, 0)
          || accumulate(arr.begin(), arr.begin()+n-1, 0) == 0) {
        return "YES";
    }
    // improving running time with shellsort 3x+1 increment sequence
    int h = 1;
    while (h < n/3) h = 3*h + 1;
    return is_pivot_found(arr, n, h);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = balancedSums(arr);

        fout << result << "\n";
    }

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

