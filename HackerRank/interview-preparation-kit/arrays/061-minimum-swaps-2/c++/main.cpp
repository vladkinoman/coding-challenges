#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int minimumSwaps(vector<int> arr) {
    int min_swaps = 0, n = arr.size();
    for(int i = 0; i < n; i++) {
        if(arr[i] == (i+1)) continue;
        swap(arr[i], arr[arr[i]-1]);
        min_swaps++;
        // if we exchanged the values on this iteration,
        // we shouldn't go on the next one.
        i--; 
    }
    return min_swaps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (n < 1 || n > pow(10, 5))
        throw invalid_argument("");
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        if (arr_item < 1 || arr_item > n)
            throw invalid_argument("");
        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
