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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode* res = new ListNode();
     ListNode* currNode = res;
     while (list1 || list2) {
        int val1 = 101;
        int val2 = 101;
        if (list1) {
            val1 = list1->val;
        }
        if (list2) {
            val2 = list2->val;
        }
        currNode->next = new ListNode(min(val1, val2));
        currNode = currNode->next;
        if (val1 < val2) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
     }
     return res->next;
}

int main()
{
    ListNode* root1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    
    ListNode* root2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* res = mergeTwoLists(root1, root2);
    cout << "Ans is ";
    while (res != nullptr) {
        cout << res->val << "->";
        res=res->next;
    }
    return 0;
}