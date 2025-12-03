#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* dfs(Node* root, unordered_map<Node*, Node*>& map) {
    if (!root)
        return root;
        
    Node* curr = new Node(root->val);
    map[root] = curr;
    
    if (root->neighbors.empty())
        return curr;
    
    vector<Node*> neighbours;
    
    for (const auto & n : root->neighbors) {
        if (map.find(n) != map.end()) {
            neighbours.push_back(map[n]);
        } else {
            neighbours.push_back(dfs(n, map));
        }
    }
    curr->neighbors = neighbours;
    return curr;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> map;
    return dfs(node, map);
}

int main()
{
    Node* A = new Node(1);
    Node* B = new Node(2);
    Node* C = new Node(3);
    Node* D = new Node(4);

    A->neighbors.push_back(B);
    A->neighbors.push_back(D);

    B->neighbors.push_back(A);
    B->neighbors.push_back(C);

    C->neighbors.push_back(B);
    C->neighbors.push_back(D);

    D->neighbors.push_back(C);
    D->neighbors.push_back(A);    
    
    Node* copied = cloneGraph(A);

    return 0;
};
