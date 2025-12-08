#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    vector<shared_ptr<Node>> children{26};
    bool isWord{false};
};

class WordDictionary {
    shared_ptr<Node> root{make_shared<Node>()};

    bool searchHelper(const shared_ptr<Node> node, const string& word, int index) const {
        if (index == word.size())
            return node->isWord;
        
        const char c = word[index];

        if (c == '.') {
            for (const auto& p : node->children) {
                if (p && searchHelper(p, word, index + 1))
                    return true;
            }
            return false;
        } else {
            const int j = word[index] - 'a';
            
            if (!node->children[j])
                return false;
            
            return searchHelper(node->children[j], word, index + 1);
        }
    }

public:
    WordDictionary() = default;
    
    void addWord(string word) {
        shared_ptr<Node> node = root;
        
        for (int i = 0; i < word.size(); i++) {
            const int j = word[i] - 'a';

            if (!node->children[j])
                node->children[j] = make_shared<Node>();

            node = node->children[j];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

int main()
{
    WordDictionary wordDictionary;

    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << "Ans is\n" << boolalpha;
    cout << wordDictionary.search("pad") << " should be false\n";
    cout << wordDictionary.search("bad") << " should be true\n";
    cout << wordDictionary.search(".ad") << " should be true\n";
    cout << wordDictionary.search("b..") << " should be true\n";
    return 0;
};
