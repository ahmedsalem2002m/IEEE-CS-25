#include <iostream>
#include <vector>

using namespace std;

bool is_safe(int row, int col, const vector<bool>& cols, const vector<bool>& diag1, const vector<bool>& diag2) {
    return !cols[col] && !diag1[row - col + 7] && !diag2[row + col];
}

int place_queens(vector<string>& board, int row, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == 8) {
        return 1;
    }
    int count = 0;
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '.' && is_safe(row, col, cols, diag1, diag2)) {
            cols[col] = true;
            diag1[row - col + 7] = true;
            diag2[row + col] = true;
            count += place_queens(board, row + 1, cols, diag1, diag2);
            cols[col] = false;
            diag1[row - col + 7] = false;
            diag2[row + col] = false;
        }
    }
    return count;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    vector<bool> cols(8, false);
    vector<bool> diag1(15, false);
    vector<bool> diag2(15, false);

    int result = place_queens(board, 0, cols, diag1, diag2);
    cout << result;

    return 0;
}
