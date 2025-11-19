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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* currNode = new ListNode();
    ListNode* res = currNode;;
    int remainder{0};
    
    while (l1 || l2 || remainder) {
        int currVal{0};
        if (l1) {
            currVal += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            currVal += l2->val;
            l2 = l2->next;
        }
        currVal += remainder;
        remainder = currVal / 10;
        currVal %= 10;
        currNode->next = new ListNode(currVal);
        currNode = currNode->next;
    }
    res = res->next;
    return res;
}

int main()
{
    ListNode* root1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    
    ListNode* root2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* res = addTwoNumbers(root1, root2);
    cout << "Ans is ";
    while (res != nullptr) {
        cout << res->val << "->";
        res=res->next;
    }
    return 0;
}