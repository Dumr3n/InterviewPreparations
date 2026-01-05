#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

bool solve(int r, int c, int rs, int cs, int k, std::vector<std::vector<char>>& board, std::string word)
{
    if (k == word.size())
        return true;
    
    if (r < 0 || r >= rs || c < 0 || c >= cs || board[r][c] != word[k])
        return false;

    char tmp = board[r][c];
    board[r][c] = '\0';
    bool res = solve(r+1, c, rs, cs, k+1, board, word) || solve(r-1, c, rs, cs, k+1, board, word) || solve(r, c-1, rs, cs, k+1, board, word) || solve(r, c+1, rs, cs, k+1, board, word);
    board[r][c] = tmp;
    return res;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    int rs = board.size();
    int cs = board[0].size();
    
    std::unordered_map<char, int> count;

    for (char c : word)
        count[c]++;
    
    if (count[word[0]] > count[word.back()])
        reverse(word.begin(), word.end());

    for (int r = 0; r < rs; r++)
        for (int c = 0; c < cs; c++)
            if (solve(r, c, rs, cs, 0, board, word))
                return true;
    return false;
}



int main()
{

    std::vector<std::vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::string word{"ABCCED"};

    std::cout << "Ans is " << std::boolalpha << exist(board, word) << std::endl;

    return 0;
};
