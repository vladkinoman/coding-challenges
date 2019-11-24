#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> absolutePermutation(int n, int k) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    if      (k == 0) return a;
    else if (n % k != 0 || n / k % 2 != 0) {
        return vector<int>() = {-1};
    }
    
    for (int i = 0; i < n; i += k) {
        for (int j = i + k, p = 0; p < k; p++, i++, j++) {
            swap(a[i], a[j]);
        }
    }
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (t < 1 || t > 10)
        throw invalid_argument(" ");
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);
        if (n < 1 || n > pow(10, 5))
            throw invalid_argument(" ");
        int k = stoi(nk[1]);
        if (k < 0 || k >= n)
            throw invalid_argument(" ");
        vector<int> result = absolutePermutation(n, k);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }
        fout << "\n";
        ofstream writefile;
        string filename = "myfile.txt";
        //The file doesn't exist
        writefile.open( filename.c_str() );
        //write something to the file
        for (int i = 0; i < result.size(); i++) {
            writefile << result[i];

            if (i != result.size() - 1) {
                writefile << " ";
            }
        }
        writefile.close();
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
