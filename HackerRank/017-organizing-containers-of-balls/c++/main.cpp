#include <bits/stdc++.h>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    if (n < 1 || n > 100)
        invalid_argument("");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (container[i][j] < 0 || container[i][j] > pow(10, 9))
                invalid_argument("");
        }
    }
    
    vector<int> box_totals(n);
    for (int i = 0; i < n; i++) {
        box_totals[i] = 0;
        for (int j = 0; j < n; j++) {
            box_totals[i] += container[i][j];
        }
    }
    
    vector<int> ball_totals(n);
    for (int i = 0; i < n; i++) {
        ball_totals[i] = 0;
        for (int j = 0; j < n; j++) {
            ball_totals[i] += container[j][i];
        }
    }
    
    sort(box_totals.begin(), box_totals.end());
    sort(ball_totals.begin(), ball_totals.end());
    for (int i = 0; i < n; i++) {
        if (box_totals[i] != ball_totals[i])
            return "Impossible"; 
    }
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
