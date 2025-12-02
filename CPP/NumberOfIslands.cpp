#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

namespace MuchMemory {
    void bfs(vector<vector<char>>& grid, int r, int c, unordered_set<string>& visited, vector<pair<int, int>> dirs) {
        queue<pair<int,int>> q;
        visited.insert(to_string(r) + "," + to_string(c));
        q.push({r, c});
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1' && visited.find(to_string(nr) + "," + to_string(nc)) == visited.end()) {
                    q.push({nr, nc});
                    visited.insert(to_string(nr) + "," + to_string(nc));
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res{0};
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_set<string> visited;

        vector<pair<int, int>> dirs {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        for (int r = 0; r < rows; r++) 
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == '1' && visited.find(to_string(r) + "," + to_string(c)) == visited.end()) {
                    res++;
                    bfs(grid, r, c, visited, dirs);
                }
        return res;
    }
}

namespace optimized {
    void bfs(const int r, const int c, vector<vector<char>>& grid, const vector<pair<int, int>>& dirs) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '2';
        while (!q.empty()) {
            const auto [row, col] = q.front();
            q.pop();
            for (const auto& [dr, dc] : dirs) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() || grid[nr][nc] != '1')
                    continue;
                q.push({nr, nc});
                grid[nr][nc] = '2';
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        const vector<pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int rows = grid.size();
        const int cols = grid[0].size();
        int res{0};

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == '1'){
                    res++;
                    bfs(r, c, grid, dirs);
                }
        return res;
    }
}

int main()
{
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}};
    cout << "Ans is " << optimized::numIslands(grid) << endl;
    return 0;
};
