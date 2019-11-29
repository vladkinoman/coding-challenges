#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    int m = queries.size();
    vector<long> overlapped_items(n);
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = queries[j][0];
            int b = queries[j][1];
            int k = queries[j][2];
            if (k == 0) continue;
            if ((i+1) >= a && (i+1) <= b) {
                overlapped_items[i] += k;
            }
        }
        if (overlapped_items[i] > max) max = overlapped_items[i];
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);
    if (n < 3 || n > pow(10,  7))
        throw invalid_argument("");
    int m = stoi(nm[1]);
    if (m < 1 || m > 2 * pow(10,  5))
        throw invalid_argument("");
    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }
        if (queries[i][0] < 1 || queries[i][0] > queries[i][1]
        || queries[i][1] > n || queries[i][2] < 0 
        || queries[i][2] > pow(10, 9))
            throw invalid_argument("");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
