#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int n = q.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    int bribes = 0;
    vector<int> vbribes(n);
    for (int i = n - 1; i >= 0;) {
        if (p[i] == q[i]) {
            --i;
            continue;
        }
        
        int j_bribes = 0;
        /*
            i - is the index for q
            j - is the index for p,
              we are trying to find the element p[j] == q[i]
        */
        for (int j = i; j - 1 >= 0 && p[j] != q[j]; --j) {
            vbribes[p[j]-1]++;
            j_bribes++;
            if (vbribes[p[j]-1] > 2) {
                cout << "Too chaotic" << endl;
                return;
            }
            swap(p[j - 1], p[j]);
        }
        bribes += j_bribes;
        
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
