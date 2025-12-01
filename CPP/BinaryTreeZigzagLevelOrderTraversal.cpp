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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }
    deque<TreeNode*> q;
    q.push_front(root);
    vector<int> midRes;
    bool left = false;
    while (!q.empty()) {
        int lvl = q.size();
        for (int i = 0; i < lvl; i++) {
            if (left) {
                TreeNode* node = q.back();
                q.pop_back();
                midRes.push_back(node->val);
                if (node->right)
                    q.push_front(node->right);
                if (node->left)
                    q.push_front(node->left);
            } else {
                TreeNode* node = q.front();
                q.pop_front();
                midRes.push_back(node->val);
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
        }
        left = !left;
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
    
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, nullptr, new TreeNode(5)));
    auto res = zigzagLevelOrder(root);
    cout << "Ans is ";
    for (const auto& vec: res) {
        for (const auto& i : vec)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}