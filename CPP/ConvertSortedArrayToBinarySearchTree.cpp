#include <iostream>

#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* solve(std::vector<int>& nums, int left, int right) {
    if (left > right)
        return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = solve(nums, left, mid - 1);
    node->right = solve(nums, mid + 1, right);
    return node;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return solve(nums, 0, nums.size() - 1);
}

void InOrderTraversal(TreeNode* root) {
    if (!root)
        return;

    if (root->left)
        InOrderTraversal(root->left);
    
    std::cout << root->val << " ";

    if (root->right)
        InOrderTraversal(root->right);
}

int main()
{
    std::vector<int> nums{-10,-3,0,5,9};
    
    TreeNode* res = sortedArrayToBST(nums);

    std::cout << "Ans is \n";
    InOrderTraversal(res);
    std::cout << std::endl;
    return 0;
};
