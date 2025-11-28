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

void bfs(TreeNode* root, vector<int>& res) {
    queue<pair<TreeNode*,int>> q;
    int lvl{1};
    q.push({root, lvl});
    while (!q.empty()) {
        TreeNode* tmp;
        while (q.front().second == lvl) {
            if (q.front().first->left)
                q.push({q.front().first->left, lvl+1});
            if (q.front().first->right)
                q.push({q.front().first->right, lvl+1});
            tmp = q.front().first;
            q.pop();
        }
        lvl++;
        res.push_back(tmp->val);
    }
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    bfs(root, res);
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
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(5), nullptr), nullptr), new TreeNode(3));
    auto res = rightSideView(root);
    cout << "Ans is ";
    for (const auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}