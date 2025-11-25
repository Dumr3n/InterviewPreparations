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

int maxDepthDFS(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + max(maxDepthDFS(root->left), maxDepthDFS(root->right));
}

int maxDepthBFS(TreeNode* root) {
    if (!root) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        depth++;
        int level = q.size();
        for (int i = 0; i < level; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }

        }
    }
    return depth;
}

int main()
{
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    //cout << "Ans is " << maxDepthDFS(root) << endl;
    cout << "Ans is " << maxDepthBFS(root) << endl;
    return 0;
}