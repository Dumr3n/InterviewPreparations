#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class BSTIterator {
    TreeNode* curr{nullptr};
public:
    BSTIterator(TreeNode* root) : curr(root) {
        
    }
    
    int next() {
        int res{-1};
        while(curr && res==-1) {
            if (!curr->left) {
                res = curr->val;
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right!=curr) 
                    prev = prev->right;
                
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    res = curr->val;
                    curr = curr->right;
                }

            }
        }
        return res;
    }
    
    bool hasNext() {
        return curr != nullptr;
    }
};


void PreOrderPrint(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    PreOrderPrint(root->left);
    PreOrderPrint(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
    BSTIterator obj{root};
    cout << obj.next() << endl;
    cout << obj.next() << endl;
    cout << boolalpha << obj.hasNext() << endl;
    cout << obj.next() << endl;
    cout << boolalpha << obj.hasNext() << endl;
    cout << obj.next() << endl;
    cout << boolalpha << obj.hasNext() << endl;
    cout << obj.next() << endl;
    cout << boolalpha << obj.hasNext() << endl;
    
    return 0;
}