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

void InOrderTraversal(TreeNode* root, int k, int& idx, int& ans) {
    if (!root) {
        return;
    }
    InOrderTraversal(root->left, k, idx, ans);
    idx++;
    if (idx == k) {
        ans = root->val;
        return;
    }
    InOrderTraversal(root->right, k, idx, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int idx{0};
    int ans{-1};
    InOrderTraversal(root, k, idx, ans);
    return ans;
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
    TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(2), nullptr), new TreeNode(4));
    int k = 1;
    cout << "Ans is " << kthSmallest(root, k) << endl;
    return 0;
}