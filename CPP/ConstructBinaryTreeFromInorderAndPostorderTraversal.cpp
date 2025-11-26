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

namespace N {
    unordered_map<int, int> map;

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int posStart, int posEnd) {
                        if (inStart > inEnd)
                            return nullptr;
                        int rootVal = postorder[posEnd];
                        int inOrderidx = map[rootVal];
                        int leftSize = inOrderidx - inStart;

                        TreeNode* node = new TreeNode(rootVal);
                        node->left = build(inorder, inStart, inOrderidx - 1, postorder, posStart, posStart + leftSize - 1);node->right = build(inorder, inOrderidx + 1, inEnd, postorder, posStart + leftSize, posEnd - 1);
                        return node;
                    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, 0, inorder.size() - 1,
                                postorder, 0, postorder.size() - 1);
        return root;
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
    
    vector<int> inorder{9,3,15,20,7};
    vector<int> postorder{9,15,7,20,3};
    TreeNode* root = N::buildTree(inorder, postorder);
    cout << "Ans is ";
    PreOrderPrint(root);
    cout << endl;
    return 0;
}