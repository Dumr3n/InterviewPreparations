#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* curr = dummy;
    for (int i = 0; i < n; i++) {
        head = head->next;
    }
    while(head) {
        dummy = dummy->next;
        head = head->next;
    }
    dummy->next = dummy->next->next;
    return curr->next;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    root = removeNthFromEnd(root, 2);
    
    cout << "Ans ";
    while(root) {
        cout << root->val << (root->next ? "->" : "");
        root = root->next;
    }
    cout << endl;
    return 0;
}