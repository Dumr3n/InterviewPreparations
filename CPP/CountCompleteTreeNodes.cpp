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

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    TreeNode* curr{root};
    int lf{0};
    int rf{0};
    while (curr->left) {
        lf++;
        curr = curr->left;
    }
    curr = root;
    if (curr->right) {
        rf++;
        curr = curr->right;
    }
    if (lf == rf) {
        return (2 << lf) - 1; // 2^lf
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
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
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));

    cout << "Ans is " << countNodes(root) << endl;
    return 0;
}