#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

bool is_attacked(int x, int y,
    vector<vector<int>> board, int N) {
    for (int i = 0; i < N; i++) {
        if (board[x][i] == 1) return true;
    }    
    for (int i = 0; i < N; i++) {
        if (board[i][y] == 1) return true;
    }
    
    for (int p = 0, q = 0; p < N && q < N; p++, q++) {
        if (board[p][q] == 
        board[x][y] && board[p][q] == 1) return true;
    }
    for (int p = 0, q = N-1; p < N && q >= 0; p++, --q) {
        if (board[p][q] == 
        board[x][y] && board[p][q] == 1) return true;
    }
    return false;
}

bool NQueens(vector<vector<int>> &board, int N) {
    if (N == 0) return true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_attacked(i, j, board, N)) {
                // skip it and move to next cell
                continue;
            }
            board[i][j] = 1;
            if (NQueens(board, N - 1)) return true;
            board[i][j] = 0;
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
	if (NQueens(board, N)) {
	    cout << "YES" << endl;
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < N; j++) {
	            cout << board[i][j] << " ";
	        }
	        cout << endl;
	    }
	} else {
	    cout << "NO" << endl;
	}
	return 0;
}
