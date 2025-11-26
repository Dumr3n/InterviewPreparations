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


void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* tmp = curr->left;
            while(tmp->right)
                tmp = tmp->right;
            tmp->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

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
    
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
    flatten(root);
    cout << "Ans is ";
    PreOrderPrint(root);
    cout << endl;
    return 0;
}