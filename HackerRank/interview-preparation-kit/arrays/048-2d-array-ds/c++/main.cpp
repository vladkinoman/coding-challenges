#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < -9 || arr[i][j] > 9)
                invalid_argument("");
        }
    }
    
    int max_hourglass_sum = INT_MIN;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int sum_of_curr_hourglas = 0;
            for (int k = 1, p = i, q = j; k <= 9; k++) {
                sum_of_curr_hourglas += arr[p][q];
                if (k == 3 || k == 5) {
                    p++;
                    if (k == 3) q = j + 1;
                    else        q = j;
                    k++;
                } else q++;
            }
            if (sum_of_curr_hourglas > max_hourglass_sum)
                max_hourglass_sum = sum_of_curr_hourglas;
        }
    }
    return max_hourglass_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
