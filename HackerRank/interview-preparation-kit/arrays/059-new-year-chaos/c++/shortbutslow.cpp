#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// My favorite solution. It's short and slow.
void minimumBribes(vector<int> q) {
    int n = q.size();
    int bribes = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (q[i] == i + 1) continue;
        auto max_in_left_subarray = max_element(q.begin(), q.begin() + i);
        int bribes_of_ith = distance(max_in_left_subarray, q.begin() + i);
        if (bribes_of_ith > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        q.erase(max_in_left_subarray);
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
