#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!q && !p) {
        return true;
    }
    if (!q || !p) {
        return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode* root1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* root2 = new TreeNode(3, new TreeNode(9, new TreeNode(4), new TreeNode(6)), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << "Ans is " << boolalpha << isSameTree(root1, root2) << endl;
    return 0;
}