#include <bits/stdc++.h>
using namespace std;
void solve(int row, int n,
           vector<string> &board,
           vector<int> &col,
           vector<int> &diag1,
           vector<int> &diag2) {

    if (row == n) {
        for (auto &r : board) cout << r << endl;
        cout << "------\n";
        return;
    }

    for (int j = 0; j < n; j++) {

        if (col[j] == 0 && diag1[row + j] == 0 && diag2[row - j + n - 1] == 0) {

            // place queen
            board[row][j] = 'Q';
            col[j] = diag1[row + j] = diag2[row - j + n - 1] = 1;

            solve(row + 1, n, board, col, diag1, diag2);

            // backtrack
            board[row][j] = '.';
            col[j] = diag1[row + j] = diag2[row - j + n - 1] = 0;
        }
    }
}
int main() {

    int n = 4;

    vector<string> board(n, string(n, '.'));
    vector<int> col(n, 0);
    vector<int> diag1(2 * n - 1, 0);
    vector<int> diag2(2 * n - 1, 0);

    solve(0, n, board, col, diag1, diag2);
    return 0;
}