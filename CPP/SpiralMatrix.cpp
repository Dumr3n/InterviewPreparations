#include <iostream>
#include <vector>
#include <utility>
#include <cctype>
#include <unordered_set>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    int x{0}, y{0}, dx{0}, dy{1};
    vector<int> res;
    for (int i = 0; i < rows*columns; i++) {
        res.push_back(matrix[x][y]);
        matrix[x][y] = -101;
        if (!(0 <= x+dx && x+dx < rows && 0 <= y+dy && y+dy < columns) || matrix[x+dx][y+dy] == -101) {
            int tmp = dy;
            dy = -dx;
            dx = tmp;
        }
        x+=dx;
        y+=dy;
    }
    return res;
}
int main()
{
    vector<vector<int>> matrix {{1,2,3,4}
                               ,{5,6,7,8}
                               ,{9,10,11,12}};

    vector<int> res = spiralOrder(matrix);

    cout << "Ans is ";

    for (const auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}