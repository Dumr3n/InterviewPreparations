#include <iostream>
#include <vector>
using namespace std;

//0 - dead originally 1, alive originally, 2 - became dead, was alive, 3 - became alive, was dead
void gameOfLife(vector<vector<int>>& board) {
    vector<pair<int, int>> neighbours {{-1, 1}, {0, 1}, {1, 1},
                                       {-1, 0},         {1, 0},
                                       {-1,-1}, {0,-1},{1,-1}};
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            int numOfLiveCells{0};
            for (const auto& [nx, ny] : neighbours) {
                if ((row + nx) >= 0 && (row + nx) < board.size() && (col + ny) >= 0 && (col+ny) < board[0].size()) {
                    if (board[row + nx][col+ny] == 1 || board[row + nx][col+ny] == 2)
                        numOfLiveCells++;
                }
            }
            if ((board[row][col] == 1) && numOfLiveCells < 2) {
                board[row][col] = 2;
                continue;
            } 
            if ((board[row][col] == 1) && (numOfLiveCells == 2 || numOfLiveCells == 3)) {
                continue;
            }
            if ((board[row][col] == 1) && numOfLiveCells > 3) {
                board[row][col] = 2;
            }
            if ((board[row][col] == 0 || board[row][col] == 2) && numOfLiveCells == 3){
                board[row][col] = 3;
            }
        }
    }
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == 2) {
                board[row][col] = 0;
            }
            if (board[row][col] == 3) {
                board[row][col] = 1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> board {{1, 1}
                               ,{1, 0}};

    gameOfLife(board);

    cout << "Ans is \n";

    for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board[0].size(); y++)
            cout << board[x][y] << " ";
        cout << endl;
    }
    return 0;
}