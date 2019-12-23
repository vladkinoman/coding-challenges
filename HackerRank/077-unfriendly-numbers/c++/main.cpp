#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(vector<int> nums, int f) {


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nf_temp;
    getline(cin, nf_temp);

    vector<string> nf = split_string(nf_temp);

    int n = stoi(nf[0]);

    int f = stoi(nf[1]);

    string nums_temp_temp;
    getline(cin, nums_temp_temp);

    vector<string> nums_temp = split_string(nums_temp_temp);

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        int nums_item = stoi(nums_temp[i]);

        nums[i] = nums_item;
    }

    int result = solve(nums, f);

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

