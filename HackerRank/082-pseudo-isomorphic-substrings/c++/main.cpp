#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pseudoIsomorphicSubstrings function below.
 */
vector<int> pseudoIsomorphicSubstrings(string s) {
    /*
     * Write your code here.
     */

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    vector<int> result = pseudoIsomorphicSubstrings(s);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
