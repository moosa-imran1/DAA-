Dclass Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, count, cols, diag1, diag2);
        return count;
    }

private:
    void backtrack(int row, int n, int& count,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, count, cols, diag1, diag2);

            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};
