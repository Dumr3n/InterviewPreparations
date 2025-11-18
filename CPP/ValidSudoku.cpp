#include <iostream>
#include <vector>
#include <utility>
#include <cctype>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> map;
    for (int row = 0; row < 9; row++) {
        map.clear();
        for (int column = 0; column < 9; column++) {
            if (map.count(board[row][column]) > 0) {
                return false;
            }
            if (isdigit(board[row][column])) {
                map.insert(board[row][column]);
            }
        }
    }

    for (int column = 0; column < 9; column++) {
        map.clear();
        for (int row = 0; row < 9; row++) {
            if (map.count(board[row][column]) > 0) {
                return false;
            }
            if (isdigit(board[row][column])) {
                map.insert(board[row][column]);
            }
        }
    }

    for (int row = 0; row < 9; row += 3) {
        for (int column = 0; column < 9; column += 3) {
            map.clear();
            for (int rowI = 0; rowI < 3; rowI++) {
                for (int columnI = 0; columnI < 3; columnI++) {
                    if (map.count(board[row+rowI][column+columnI]) > 0) {
                        return false;
                    }
                    if (isdigit(board[row+rowI][column+columnI])) {
                        map.insert(board[row+rowI][column+columnI]);
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board  {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    cout << boolalpha;
    cout << "Is sudoku valid " << isValidSudoku(board) << endl;
    return 0;
}