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


void dfs(TreeNode* root, int& diff, int& prev) {
    if (root->left) 
        dfs(root->left, diff, prev);
    if (prev != -1)
        diff = min(diff, root->val - prev);
    prev = root->val;
    if (root->right)
        dfs(root->right, diff, prev);
}

int getMinimumDifference(TreeNode* root) {
    int diff = INT_MAX;
    int prev = -1;
    dfs(root, diff, prev);
    return diff;
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
    
    TreeNode* root = new TreeNode(5, new TreeNode(4), new TreeNode(7));
    cout << "Ans is " << getMinimumDifference(root) << endl;
    return 0;
}