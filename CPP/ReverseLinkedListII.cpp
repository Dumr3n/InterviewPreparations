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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left==right) {
        return head;
    }

    ListNode* dummy = new ListNode(0, head);
    ListNode* leftOne = dummy;

    for (int i = 0; i < left - 1; i++) {
        leftOne = leftOne->next;
    }

    ListNode* current = leftOne->next;

    for (int i = 0; i < right - left; i++) {
        ListNode* tmp = current->next;
        current->next = tmp->next;
        tmp->next = leftOne->next;
        leftOne->next = tmp;
    }

    return dummy->next;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8, new ListNode(9)))))))));
    ListNode* ans = reverseBetween(root, 2, 6);
    cout << "Ans is ";
    while (ans) {
        cout << ans->val << (ans->next ? "->" : "");
        ans = ans->next;
    }
    cout << endl;
    return 0;
}