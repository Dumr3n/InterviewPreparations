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

ListNode* reverse(ListNode* start, ListNode* end) {
    ListNode* prev = nullptr;
    while (start != end) {
        ListNode* tmp = start->next;
        start->next = prev;
        prev = start;
        start = tmp;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return head;

    ListNode* rightOne = head;
    for (int i = 0; i < k; i++) {
        if (!rightOne) return head;
        rightOne = rightOne->next;
    }
    ListNode* newHead = reverse(head, rightOne);
    head->next = reverseKGroup(rightOne, k);
    return newHead;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8, new ListNode(9)))))))));
    ListNode* ans = reverseKGroup(root, 2);
    cout << "Ans is ";
    while (ans) {
        cout << ans->val << (ans->next ? "->" : "");
        ans = ans->next;
    }
    cout << endl;
    return 0;
}