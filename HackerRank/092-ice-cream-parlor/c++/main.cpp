#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the icecreamParlor function below.
vector<int> icecreamParlor(int m, vector<int> arr) {
	vector<int> a(arr);
    int n = a.size();
    sort(a.begin(), a.end());

    int i = 0, j = n-1;
    for (int k = 1; true; i = 0, j = n-1, k++) {
        j = lower_bound(a.begin(), a.begin()+n, m-k) - a.begin();
        i = lower_bound(a.begin(), a.begin()+j, k)   - a.begin();

        if (i < n && a[i] == k && j < n && a[j] == m-k) break;    
    }
    
    int p = 0, q = 0;
    // Johnny never buys the same flavor that Sunny does
    p = find(arr.begin(), arr.end(), a[i]) - arr.begin();
    q = find(arr.begin(), arr.end(), a[j]) - arr.begin();
    if (a[i] == a[j]) {
        q = find(arr.begin()+q+1, arr.end(), a[j]) - arr.begin();    
    }
    if (p > q) swap(q, p);
    return { p+1, q+1 };
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = icecreamParlor(m, arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
