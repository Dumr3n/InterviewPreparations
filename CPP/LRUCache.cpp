#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    int key;
    Node* prev;
    Node* next;
    Node() : val(0), key(0), next(nullptr), prev(nullptr) {}
    Node(int val, int key) : val(val), key(key), next(nullptr), prev(nullptr) {}
    Node(int val, int key, Node* next) : val(val), key(key), next(next), prev(nullptr) {}
    Node(int val, int key, Node* next, Node* prev) : val(val), key(key), next(next), prev(prev) {}
};

class LRUCache {
    unordered_map<int, Node*> cache;
    Node* oldest;
    Node* newest;
    int size;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = newest->prev;
        Node* next = newest;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
    }

public:
    LRUCache(int capacity) : size(capacity) {
        oldest = new Node();
        newest = new Node();
        oldest->next = newest;
        newest->prev = oldest;
    }

    ~LRUCache() {
        Node* curr = oldest;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* node = new Node(value, key);
        cache[key] = node;
        insert(node);

        if (cache.size() > size) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
int main()
{
    LRUCache obj(1);
    obj.put(2, 1);
    cout << "Ans " << obj.get(2) << endl;
    return 0;
}