#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

namespace bfs {
    void bfs(vector<vector<char>>& board, const vector<pair<int, int>> dirs, const int r, const int c) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> visited;
        q.push({r, c});
        visited.push_back({r, c});
        bool edge{false};
        while (!q.empty() && !edge) {
            auto [row, col] = q.front();

            q.pop();
            for (const auto & [dr, dc] : dirs) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                    if (board[nr][nc] == 'O') {
                        if (nr > 0 && nr < board.size() - 1 && nc > 0 && nc < board[0].size() - 1) {
                            board[nr][nc] = 'N';
                            q.push({nr, nc});
                            visited.push_back({nr, nc});
                        } else {
                            edge = true;
                        }
                    }
                }
            }
        }
        for (const auto & [dr, dc] : visited)
            board[dr][dc] = edge ? 'O' : 'X';
    }

    void solve(vector<vector<char>>& board) {
        const int rows = board.size();
        const int cols = board[0].size();
        const vector<pair<int, int>> dirs {{0, 0}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int r = 0; r < rows - 1; r++)
            for (int c = 0; c < cols - 1; c++)
                if (board[r][c] == 'O')
                    bfs(board, dirs, r, c);
    }
}

namespace dfs {

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        const int rows = board.size();
        const int cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || board[row][col] == 'X')
            return;
        visited[row][col] = true;
        
        dfs(row+1, col, board, visited);
        dfs(row, col+1, board, visited);
        dfs(row-1, col, board, visited);
        dfs(row, col-1, board, visited);
    }

    void solve(vector<vector<char>>& board) {
        const int rows = board.size();
        const int cols = board[0].size();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, board, visited);
            }
            if (board[i][cols-1] == 'O' && !visited[i][cols-1]) {
                dfs(i, cols-1, board, visited);
            }
        }
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, board, visited);
            }
            if (board[rows-1][i] == 'O' && !visited[rows-1][i]) {
                dfs(rows-1, i, board, visited);
            }
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
    }
}
int main()
{
    vector<vector<char>> grid{{'X', 'O', 'X'},
                              {'O', 'X', 'O'},
                              {'X', 'O', 'X'}};
    dfs::solve(grid);
    for (const auto & row : grid) {
        for (const auto & col : row) 
            cout << col << " ";
        cout << endl;
    }
    return 0;
};
