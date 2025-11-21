#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
    
};

ListNode* reverseListIt(ListNode* head) {
    if (!head) {
        return head;
    }

    ListNode* newRoot = nullptr;

    while (head) {
        ListNode* curr = head->next;
        head->next = newRoot;
        newRoot = head;
        head = curr;
    }
    return newRoot;
}

ListNode* reverseListRec(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* curr = reverseListRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return curr;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    //ListNode* ans = reverseListIt(root);
    ListNode* ans = reverseListRec(root);
    cout << "Ans is ";
    while (ans) {
        cout << ans->val << (ans->next ? "->" : "");
        ans = ans->next;
    }
    cout << endl;
    return 0;
}