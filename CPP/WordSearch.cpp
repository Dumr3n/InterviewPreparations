#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord{false};
    ~TrieNode() {
        for (auto& a : children)
            delete a.second;
    }
};

struct Trie {
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    ~Trie() {delete root;}

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
};

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    if (board.empty() || board[0].empty() || words.empty())
        return {};
    
    Trie trie;
    for (auto& w : words) 
        trie.insert(w);
    
    int rows = board.size();
    int cols = board[0].size();

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::unordered_set<std::string> resultSet;
    std::string path;
    path.reserve(32);

    std::function<void(int, int, TrieNode*)> backtrack = [&](int row, int col, TrieNode* node) {
        if (node->isEndOfWord) {
            resultSet.insert(path);
            node->isEndOfWord = false;
        }

        visited[row][col] = true;
        static const int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& d : DIRS) {
            int nr = row + d[0], nc = col + d[1];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                continue;
            if (visited[nr][nc])
                continue;
            char nextChar = board[nr][nc];
            auto it = node->children.find(nextChar);
            if (it != node->children.end()) {
                path.push_back(nextChar);
                backtrack(nr, nc, it->second);
                path.pop_back();
            }
        }
        visited[row][col] = false;
    };

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            char start = board[r][c];
            auto it = trie.root->children.find(start);
            if (it != trie.root->children.end()) {
                path.clear();
                path.push_back(start);
                backtrack(r, c, it->second);
            }
        }
    }
    std::vector<std::string> result(resultSet.begin(), resultSet.end());
    return result;
}

int main()
{
    std::vector<std::vector<char>> board {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    std::vector<std::string> words {"oath", "pea", "eat", "rain"};
    std::vector<std::string> res = findWords(board, words);

    std::cout << "Ans is \n";
    for (const auto& i : res)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
};
