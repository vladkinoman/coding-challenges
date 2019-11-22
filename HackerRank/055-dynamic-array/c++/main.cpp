#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> dynamicArray(int N, vector<vector<int>> queries) {
    vector<vector<int>> seq_list(N);
    int last_answer = 0;
    vector<int> last_answers;
    for (int i = 0; i < queries.size(); i++) {
        int x = queries[i][1];
        int y = queries[i][2];
        if (queries[i][0] == 1) {
            seq_list[(x ^ last_answer) % N].push_back(y);
        } else {
            vector<int> * seq = &seq_list[(x ^ last_answer) % N];
            last_answer = seq->at(y % seq->size());
            last_answers.push_back(last_answer);
        }
    }
    return last_answers;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    if (n < 1 || n > pow(10, 5))
        throw invalid_argument(" ");
    int q = stoi(first_multiple_input[1]);
    if (q < 1 || q > pow(10, 5))
        throw invalid_argument(" ");
    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);
            if (j == 0 && queries_row_item != 1 && queries_row_item != 2)
                    throw invalid_argument(" ");
            else {
                if (queries_row_item < 0 || queries_row_item > pow(10, 9))
                    throw invalid_argument(" ");
            }
            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = dynamicArray(n, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
