#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int val) : val(val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int val, Node* left, Node* right, Node* next) : val(val), left(left), right(right), next(next) {}
};

Node* connect(Node* root) {
    if (!root) {
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int level = q.size();
        for (int i = 0; i < level; i++) {
            Node* curr = q.front();
            q.pop();
            if (i < level - 1) {
                curr->next = q.front();
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return root;
}

void PreOrderPrint(Node* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    PreOrderPrint(root->left);
    PreOrderPrint(root->right);
}

int main()
{
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr), new Node(3, nullptr, new Node(7), nullptr), nullptr);
    root = connect(root);
    cout << "Ans is ";
    PreOrderPrint(root);
    cout << endl;
    return 0;
}