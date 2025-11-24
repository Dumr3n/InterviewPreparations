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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(0,head);
    ListNode *prev=dummy;
    while (head) {
       if(head->next && head->val == head->next->val) {
            while(head->next && head->val == head->next->val) 
                head=head->next;
            prev->next=head->next;
            } else prev=prev->next;
            head=head->next;
        }    
    return dummy->next;
}

int main()
{
    ListNode* root = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5))))))));

    root = deleteDuplicates(root);
    
    cout << "Ans ";
    while(root) {
        cout << root->val << (root->next ? "->" : "");
        root = root->next;
    }
    cout << endl;
    return 0;
}