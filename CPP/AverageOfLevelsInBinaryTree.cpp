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


vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (!root) {
        return res;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int lvl = q.size();
        double sum{0};
        int count{0};
        for (int i = 0; i < lvl; i++) {
            sum += q.front()->val;
            count++;
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        res.push_back(sum / count);
    }
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
    
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));
    auto res = averageOfLevels(root);
    cout << "Ans is ";
    for (const auto& i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}