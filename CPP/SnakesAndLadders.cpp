#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> minRolls(n * n + 1, -1);
    queue<int> q;
    minRolls[1] = 0;
    q.push(1);
    int y;
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6 && x + i <= n * n; i++) {
            int t = x + i, row = (t - 1) / n, col = (t - 1) % n;
            int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
            y = v > 0 ? v : t;

            if (y == n*n) {
                return minRolls[x] + 1;
            };
            if (minRolls[y] == -1) {
                minRolls[y] = minRolls[x] + 1;
                q.push(y);
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> board =  {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    cout << "Ans is " << snakesAndLadders(board) << endl;

    return 0;
};
