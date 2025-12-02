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

bool checkRange(TreeNode* root, long min, long max) {
    if (!root) {
        return true;
    }
    if (!(root->val > min && root->val < max))
        return false;
    return checkRange(root->left, min, root->val) && checkRange(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    return checkRange(root, LONG_MIN, LONG_MAX);
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
    TreeNode* root = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    cout << "Ans is " << boolalpha << isValidBST(root) << endl;
    return 0;
}