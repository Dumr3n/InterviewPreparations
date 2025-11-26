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

void doDFSSum(TreeNode* root, int currentSum, int& resultSum) {
    if (root) {
        currentSum = currentSum*10 + root->val;
        if (!root->left && !root->right) {
            resultSum += currentSum;
            return;
        }
        doDFSSum(root->left, currentSum, resultSum);
        doDFSSum(root->right, currentSum, resultSum);
    }
}

int sumNumbers(TreeNode* root) {
    int result{0};
    doDFSSum(root, 0, result);
    return result;
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
    
    TreeNode* root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    cout << "Ans is " << sumNumbers(root) << endl;
    return 0;
}