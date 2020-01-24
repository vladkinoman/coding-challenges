#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

// Driver function to sort the 2D vector 
// on basis of a particular column 
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
    return v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] < v2[0]); 
} 
  
// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {
    vector<vector<int>> vt(orders.size());
    for (int i = 0; i < orders.size(); i++) {
        vt[i].resize(2);
        vt[i][0] = i + 1;
        vt[i][1] = orders[i][0] + orders[i][1];
    }
    sort(vt.begin(), vt.end(), sortcol);
    vector<int> jimorders(orders.size());
    for (int i = 0; i < orders.size(); i++) {
        jimorders[i] = vt[i][0];
    }
    return jimorders;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (n < 1 || n > pow(10, 3))
        throw invalid_argument("");
    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
            if (orders[i][j] < 1 || orders[i][j] > pow(10, 6))
                throw invalid_argument("");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
