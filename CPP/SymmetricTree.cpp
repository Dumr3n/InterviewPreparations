#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

bool isMirror(TreeNode* node1, TreeNode* node2) {
    if (!node1 && !node2) {
        return true;
    }

    if (!node1 || !node2) {
        return false;
    }
    return node1->val == node2->val && isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root->left, root->right);
}

void InOrderPrint(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    InOrderPrint(root->left);
    InOrderPrint(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    cout << "Before was ";
    InOrderPrint(root);
    cout << endl;
    cout << "Ans is " << boolalpha << isSymmetric(root) << endl;
    return 0;
}