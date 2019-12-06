#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int max_toys = 0;
    int n = prices.size();
    int sum = 0;
    for (int i = 0; sum < k && i < n; i++) {
        if (sum + prices[i] > k) break;
        sum += prices[i];
        max_toys++;
    }
    return max_toys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);
    if (n < 1 || n > pow(10, 5))
        throw invalid_argument("");
    int k = stoi(nk[1]);
    if (k < 1 || k > pow(10, 9))
        throw invalid_argument("");
    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);
        if (prices_item < 1 || prices_item > pow(10, 9))
            throw invalid_argument("");
        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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
