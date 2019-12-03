#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
input:
    n: the integer number of sticks to buy
    k: the integer number of box sizes the store carries
    b: the integer number of boxes to buy
output:
For each trip to the store:
    If there is no solution, print -1 on a new line.
    If there is a solution, print a single line of  
        distinct space-separated integers where each 
        integer denotes the numbers of noodles in each
        box that Papyrus must purchase.
    If there are multiple possible solutions, you can
        print any one of them. Do not print any leading or
        trailing spaces or extra newlines.
*/
vector<long> bonetrousle(long n, long k, int b) {
    set<long> boxes_in_store;
    set<long> intact_boxes;
    for (long i = 0; i < k; i++) {
        intact_boxes.emplace(i + 1);
        boxes_in_store.emplace(i + 1);
    }
    
    long sticks_we_can_buy = 0;
    auto rev_box_iter = boxes_in_store.rbegin();
    for (long i = 0; i < k && rev_box_iter != boxes_in_store.rend();
        i++, rev_box_iter++) {
        // i - an amount of boxes we can buy
        // j - an index to the box
        sticks_we_can_buy += *rev_box_iter;
    }
    if (sticks_we_can_buy < n) return vector<long>() = {-1};
    
    vector<long> boxes_we_can_buy(b);
    short start = 0;
    while (true) {
        long sum = 0;
        auto it = intact_boxes.begin();
        for (int i = 0; i < start; i++, it++) ;
        for (int j = 0; j < b - 1; it++, j++) {
            if (it == intact_boxes.end()) 
                it = intact_boxes.begin();
            sum += *it;
            boxes_we_can_buy[j] = *it;
            it = intact_boxes.erase(it);
        }
        auto last_item = intact_boxes.find(n - sum);
        if (last_item != intact_boxes.end()) {
            boxes_we_can_buy[b-1] = *last_item;
            break;
        }
        intact_boxes = boxes_in_store;
        start++;
    }
    return boxes_we_can_buy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (t < 1 || t > 20)
        throw invalid_argument("");

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nkb_temp;
        getline(cin, nkb_temp);

        vector<string> nkb = split_string(nkb_temp);

        long n = stol(nkb[0]);
        if (n < 1 || n > pow(10, 18))
            throw invalid_argument("");
        long k = stol(nkb[1]);
        if (k < 1 || k > pow(10, 18))
            throw invalid_argument("");
        int b = stoi(nkb[2]);
        if (b < 1 || b > pow(10, 5) || b > k)
            throw invalid_argument("");
        vector<long> result = bonetrousle(n, k, b);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
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
