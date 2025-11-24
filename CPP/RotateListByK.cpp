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

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || !k)  {
        return head;
    }
    int listSize = 1;
    ListNode* curr = head;
    while (curr->next) {
        curr = curr->next;
        listSize++;
    }
    int actualOffset = k % listSize;
    if (actualOffset == 0) {
        return head;
    }
    ListNode* newEnd = head;
    for (int i = 0; i < listSize - actualOffset - 1; i++) {
        newEnd = newEnd->next;
    }
    ListNode* res = newEnd->next;
    newEnd->next = nullptr;
    curr->next = head;
    return res;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(2));

    root = rotateRight(root, 1);
    
    cout << "Ans ";
    while(root) {
        cout << root->val << (root->next ? "->" : "");
        root = root->next;
    }
    cout << endl;
    return 0;
}