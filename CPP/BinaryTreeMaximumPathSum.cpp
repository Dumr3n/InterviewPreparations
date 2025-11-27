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

int dfs(TreeNode* root, int& res) {
    if (!root) {
        return 0;
    }

    int leftSum = max(0, dfs(root->left, res));
    int rightSum = max(0, dfs(root->right, res));

    res = max(res, leftSum + rightSum + root->val);

    return max(leftSum, rightSum) + root->val;
}

int maxPathSum(TreeNode* root) {
    int res = root->val;
    dfs(root, res);
    return res;
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
    TreeNode* root = new TreeNode(-10, new TreeNode(9, new TreeNode(5), nullptr), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << "Ans is " << maxPathSum(root) << endl;
    return 0;
}