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



bool hasPathSum(TreeNode* root, int targetSum) {
    if (root) {
        return ((targetSum - root->val) == 0 && !root->left && !root->right) || hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
    return false;
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
    
    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1))));
    cout << "Ans is " << boolalpha << hasPathSum(root, 22) << endl;
    // PreOrderPrint(root);
    // cout << endl;
    return 0;
}