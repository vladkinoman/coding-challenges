#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

bool is_attacked(int x, int y,
    vector<vector<int>> board) {
    int n = board.size();
    // Checking for row and column.
    for (int i = 0; i < n; i++) {
        if (board[x][i] == 1) return true;
    }    
    for (int i = 0; i < n; i++) {
        if (board[i][y] == 1) return true;
    }
    
    // Checking for diagonals.
    for (int p = x - 1, q = y - 1;
        p >= 0 && q >= 0; --p, --q) {
        if (board[p][q] == 1) return true;
    }
    // \ → main diagonal, downwards
    for (int p = x + 1, q = y + 1;
        p < n && q < n; p++, q++) {
        if (board[p][q] == 1) return true;
    }
    // / → anti-diagonal (or counter-diagonal), upwards
    for (int p = x - 1, q = y + 1;
        p >= 0 && q < n; --p, q++) {
        if (board[p][q] == 1) return true;
    }
    // / → anti-diagonal (or counter-diagonal), downwards
    for (int p = x + 1, q = y - 1;
        p < n && q >= 0; p++, --q) {
        if (board[p][q] == 1) return true;
    }
    
    return false;
}

bool NQueens(vector<vector<int>> &board, int N) {
    int n = board.size();
    // All queens have been placed.
    if (N == 0) return true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_attacked(i, j, board)) {
                // Skip it and move to next cell.
                continue;
            }
            // Place current queen at cell (i,j).
            board[i][j] = 1;
            // Solve subproblem.
            //  if solution is found return true.
            if (NQueens(board, N - 1)) return true;
            //  if solution is not found undo whatever changes 
            //  were made i.e., remove  current queen from (i,j).
            board[i][j] = 0; // Backtrack.
        }
    }
    return false;
}

int main() {
	int N;
	cin >> N;
	if (N < 1 || N > 10)
	    throw invalid_argument("");
	vector<vector<int>> board(N, vector<int>(N));
	int n = board.size();
	if (NQueens(board, N)) {
	    cout << "YES" << endl;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cout << board[i][j] << " ";
	        }
	        cout << endl;
	    }
	} else {
	    cout << "NO" << endl;
	}
	return 0;
}
