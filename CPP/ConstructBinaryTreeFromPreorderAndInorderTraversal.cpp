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

namespace N2 {
    TreeNode* build(deque<int>& preoder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int val = preoder.front();
            preoder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), val);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(val);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
            vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preoder, leftInorder);
            root->right = build(preoder, rightInorder);

            return root;
        }
        return nullptr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderQ(preorder.begin(), preorder.end());
        return build(preorderQ, inorder);
    }
}

namespace N {
    int preorderIndex;
    unordered_map<int, int> map;

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) 
            return nullptr;
        
        int val = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(val);
        int mid = map[val];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
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
    
    vector<int> preoder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    TreeNode* root = N::buildTree(preoder, inorder);
    cout << "Ans is ";
    PreOrderPrint(root);
    cout << endl;
    return 0;
}