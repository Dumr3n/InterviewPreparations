#include <iostream>
#include <vector>
#include <utility>
#include <cctype>
#include <unordered_set>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    for (int squares = 0; squares <= size / 2; squares++) {
        int x = squares;
         while (x < size - squares - 1) {
            int tmp = matrix[squares][x];
            matrix[squares][x] = matrix[size - x - 1][squares];
            matrix[size - x - 1][squares] = matrix[size - squares - 1][size - x - 1];
            matrix[size - squares - 1][size - x - 1] = matrix[x][size - squares - 1];
            matrix[x][size - squares - 1] = tmp;
            x++;
        }
    }
}

int main()
{
    vector<vector<int>> matrix {{1,2,3}
                               ,{4,5,6}
                               ,{7,8,9}};

    rotate(matrix);

    cout << "Ans is \n";

    for (int x = 0; x < matrix.size(); x++) {
        for (int y = 0; y < matrix[0].size(); y++)
            cout << matrix[x][y] << " ";
        cout << endl;
    }
    return 0;
}