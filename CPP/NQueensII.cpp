#include <iostream>
#include <vector>
#include <unordered_map>

int solve(std::vector<bool>& col, std::vector<bool>& diag, std::vector<bool>& antiDiag, int row) {
    int n = col.size(), count = 0;
    
    if (row == n) return 1;

    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag[row + c] && !antiDiag[row - c + n - 1]) {
            col[c] = diag[row + c] = antiDiag[row - c + n - 1] = true;
            count += solve(col, diag, antiDiag, row + 1);
            col[c] = diag[row + c] = antiDiag[row - c + n - 1] = false;
        }
    }
    return count;
}

int totalNQueens(int n) {
    std::vector<bool> col(n), diag(2*n-1), antiDiag(2*n-1);
    return solve(col, diag, antiDiag, 0);
}

int main()
{

    int n = 4;

    std::cout << "Ans is " << totalNQueens(n) << std::endl;

    return 0;
};
