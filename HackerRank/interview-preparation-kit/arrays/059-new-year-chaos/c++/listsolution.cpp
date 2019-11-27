#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Tried to optimize solution with list to pass through time test cases.
void minimumBribes(vector<int> q) {
    list<int> lq(q.begin(), q.end());
    int n = lq.size();
    int bribes = 0;
    list<int>::reverse_iterator it_i = lq.rbegin();
    for (int i = n - 1; i >= 0; i--, it_i = lq.rbegin()) {
        if (*it_i == i + 1) continue;
        int max_index = 0;
        auto max_in_left_subarray = lq.begin();
        auto it_j = lq.begin();
        for (int j = 0; j <= i; j++, it_j++) {
            if (*it_j > *max_in_left_subarray) {
                max_in_left_subarray = it_j;
                max_index = j;
            }
        }
        int bribes_of_ith = i - max_index;
        if (bribes_of_ith > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        lq.erase(max_in_left_subarray); // only O(n)
        bribes += bribes_of_ith;
    }
    cout << bribes << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (t < 1 || t > 10)
        throw invalid_argument("");
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);
            if (q_item < 1 || q_item > pow(10, 5))
                throw invalid_argument("");
            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
