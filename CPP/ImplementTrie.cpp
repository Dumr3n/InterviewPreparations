#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace vec {
    struct Node {
        vector<shared_ptr<Node>> children{26};
        bool isWord{false};
    };

    class Trie {
        shared_ptr<Node> root = make_shared<Node>();

        shared_ptr<Node> find(const string& str) {
            shared_ptr<Node> node = root;

            for (const char c : str) {
                const int i = c - 'a';

                if (!node->children[i])
                    return nullptr;

                node = node->children[i];
            }

            return node;
        }

    public:
        Trie() = default;

        void insert(const string& word) {
            shared_ptr<Node> node = root;

            for (const char c : word) {
                const int i = c - 'a';

                if (!node->children[i])
                    node->children[i] = make_shared<Node>();

                node = node->children[i];
            }
            node->isWord = true;
        }

        bool search(string word) {
            shared_ptr<Node> node = find(word);
            return node && node->isWord;
        }

        bool startsWith(string prefix) {
            return find(prefix) != nullptr;
        }
    };
}

namespace map {
        struct Node {
        unordered_map<char, shared_ptr<Node>> children;
        bool isWord{false};
    };

    class Trie {
        shared_ptr<Node> root = make_shared<Node>();

        shared_ptr<Node> find(const string& str) {
            shared_ptr<Node> node = root;

            for (const char c : str) {

                if (!node->children[c])
                    return nullptr;

                node = node->children[c];
            }

            return node;
        }

    public:
        Trie() = default;

        void insert(const string& word) {
            shared_ptr<Node> node = root;

            for (const char c : word) {

                if (!node->children[c])
                    node->children[c] = make_shared<Node>();

                node = node->children[c];
            }
            node->isWord = true;
        }

        bool search(string word) {
            shared_ptr<Node> node = find(word);
            return node && node->isWord;
        }

        bool startsWith(string prefix) {
            return find(prefix) != nullptr;
        }
    };
}


int main()
{
    map::Trie trie;
    trie.insert("apple");
    cout << "Ans is \n";
    cout << boolalpha << trie.search("apple") << " should be true\n";
    cout << boolalpha << trie.search("app") << " should be false\n";
    cout << boolalpha << trie.startsWith("app") << " should be true\n";
    trie.insert("app");
    cout << boolalpha << trie.search("app") << " should be true\n";

    return 0;
};
