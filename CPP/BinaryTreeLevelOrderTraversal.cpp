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


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    vector<int> midRes;
    while (!q.empty()) {
        int lvl = q.size();
        for (int i = 0; i < lvl; i++) {
            midRes.push_back(q.front()->val);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        result.push_back(midRes);
        midRes.clear();
    }
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
    
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    auto res = levelOrder(root);
    cout << "Ans is ";
    for (const auto& vec: res) {
        for (const auto& i : vec)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}