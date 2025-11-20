#include <iostream>
#include <unordered_map>

using namespace std;
struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    Node* copied = head;
    unordered_map<Node*, Node*> map;
    while (copied) {
        map[copied] = new Node(copied->val);
        copied = copied->next;
    }
    copied = head;
    while (copied) {
        Node* curr = map[copied];
        curr->next = map[copied->next];
        curr->random = map[copied->random];
        copied = copied->next;
    }
    return map[head];
}

int main()
{
    Node* root = new Node(42);
    root->next = new Node(0);
    root->next->next = new Node(12);
    root->next->next->next = new Node(4);
    root->random = root->next->next;
    root->next->random = root->next->next->next;
    Node* res = copyRandomList(root);
    cout << "Ans is ";
    while (res != nullptr) {
        cout << res->val << " random (" << (res->random ? res->random->val : -1) << ")\n";
        res=res->next;
    }
    return 0;
}