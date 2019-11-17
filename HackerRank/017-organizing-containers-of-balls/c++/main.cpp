#include <bits/stdc++.h>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

template<class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}

bool isDiagonalMatrix(vector<vector<int>> mat, vector<int> nOfItemsOfType) {
    int n = mat.size();
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int>::iterator key = binary_find(nOfItemsOfType.begin(),
             nOfItemsOfType.end(), mat[i][j]);
            if (key != nOfItemsOfType.end()) {
                found++;
                *key = -1;
                sort(nOfItemsOfType.begin(), nOfItemsOfType.end());
            }   
        }
    }
    cout << "found = " << found << endl;
    if (found == n) return true;
    return false; 
} 

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

    vector<int> nOfItemsOfType(n);
    for (int i = 0; i < n; i++) {
        nOfItemsOfType[i] = 0;
        for (int j = 0; j < n; j++) {
            nOfItemsOfType[i] += container[j][i];
        }
    }
    sort(nOfItemsOfType.begin(), nOfItemsOfType.end());
    while (true) {
        if (isDiagonalMatrix(container, nOfItemsOfType)) {
            
            break;
        }
    
        int i = 0, j = 0;
        while (true) {
            bool isFound = false;
            for (; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (container[i][j] != 0) {
                        cout << "OK" << endl;
                        isFound = true;
                        break;
                    }
                }
                if (isFound) break;
            }
            if (!isFound) return "Impossible";
            isFound = false;
            for (int p = 0; p < n; p++) {
                if (p == i) continue;
                for (int q = 0; q < n; q++) {
                    if (q == j || (i % 2 != (p + q) % 2 
                    && container[i][q] == 0 
                    && container[p][j] == 0)) 
                        continue;
                    
                    if (container[p][q] == container[i][j]) {
                        
                        isFound = true;
                        container[i][q] += container[p][q];
                        container[p][q] = 0;
                        container[p][j] += container[i][j];
                        container[i][j] = 0;
                        for (int k = 0; k < n; k++) {
                            for (int l = 0; l < n; l++) {
                                cout << container[k][l] << " ";
                            }
                            cout << endl;
                        }
                        break;
                    }
                }
                if (isFound) break;
            }
            if (isFound) break;
            i++;
        }
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
