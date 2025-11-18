#include <iostream>
#include <vector>
#include <utility>
#include <cctype>
#include <unordered_set>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
    bool zeroInFirst{false};

    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) zeroInFirst = true;
        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
    }
        for (int x = 0; x < matrix.size(); x++) {
        for (int y = 0; y < matrix[0].size(); y++)
            cout << matrix[x][y] << " ";
        cout << endl;
    }
    for (int i = matrix.size() - 1; i >= 0; i--) {
        for (int j = matrix[0].size() - 1; j>0; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (zeroInFirst) {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix {{1, 2, 3, 4}
                               ,{5, 0, 7, 8}
                               ,{0, 10,11,12}
                               ,{13,14,15,0}};

    setZeroes(matrix);

    cout << "Ans is \n";

    for (int x = 0; x < matrix.size(); x++) {
        for (int y = 0; y < matrix[0].size(); y++)
            cout << matrix[x][y] << " ";
        cout << endl;
    }
    return 0;
}