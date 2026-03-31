class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> uldCheck;
    unordered_map<int, bool> bldCheck;
    vector<vector<string>> finalAnswer;

    void addAnswer(vector<string>& board, int& n) {
        finalAnswer.emplace_back(board);
    }

    bool isSafe(vector<string>& board, int& row, int& col, int& n) {

        if (rowCheck[row] || uldCheck[col - row] || bldCheck[row + col])
            return false;

        return true;
    }

    void place(int& row, int& col, bool val) {
        rowCheck[row] = val;
        uldCheck[col - row] = val;
        bldCheck[row + col] = val;
    }

    void nQueen(vector<string>& board, int& col, int& n) {

        if (col >= n) {
            addAnswer(board, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                place(row, col, true);
                nQueen(board, ++col, n);
                board[row][--col] = '.';
                place(row, col, false);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int col = 0;
        nQueen(board, col, n);
        return finalAnswer;
    }
};