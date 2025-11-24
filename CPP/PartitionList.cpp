#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* lessThan = new ListNode();
    ListNode* biggerThan = new ListNode();
    ListNode* biggeThanBegin = biggerThan;
    ListNode* res = lessThan;
    while(head) {
        if (head->val < x) {
            lessThan->next = head;
            lessThan = lessThan->next;
        } else {
            biggerThan->next = head;
            biggerThan = biggerThan->next;
        }
        head = head->next;
    }
    biggerThan->next = nullptr;
    lessThan->next = biggeThanBegin->next;
    return res->next;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));

    root = partition(root, 3);
    
    cout << "Ans ";
    while(root) {
        cout << root->val << (root->next ? "->" : "");
        root = root->next;
    }
    cout << endl;
    return 0;
}