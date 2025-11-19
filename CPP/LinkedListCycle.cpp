#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode* first = head;
    ListNode* second = head;
    while (first->next != nullptr && second->next != nullptr && second->next->next != nullptr) {
        first = first->next;
        second = second->next->next;
        if (first == second)
            return true;
    }
    return false;
}

int main()
{
    ListNode* root = new ListNode(3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = root->next;
    
    cout << "Has cycle " << boolalpha << hasCycle(root) << endl;
    return 0;
}