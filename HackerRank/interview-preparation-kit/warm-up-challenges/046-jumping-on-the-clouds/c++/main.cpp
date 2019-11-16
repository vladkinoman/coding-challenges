#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

vector<string> split_string(string);

int jump(vector<int> c, int i, int jumps) {
    if (i >= c.size() - 1) return jumps;
    if (c[i] == 1) return -1;
    int jumps1 = jump(c, i + 1, jumps + 1);
    int jumps2 = jump(c, i + 2, jumps + 1);
    if      (jumps1 == - 1) return jumps2;
    else if (jumps2 == - 1) return jumps1;
    return jumps1 < jumps2 ? jumps1 : jumps2;
}

int jumpingOnClouds(vector<int> c) {
    int n = c.size();
    if (n < 2 || n > 100) 
        throw std::invalid_argument(" ");
    if (c[0] != 0 || c[n - 1] != 0) 
        throw std::invalid_argument(" ");
    for (int i = 1; i < n - 1; i++) {
        if (c[i] != 0 && c[i] != 1) 
            throw std::invalid_argument(" ");
    }

    return jump(c, 0, 0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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
