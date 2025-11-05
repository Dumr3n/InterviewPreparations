#include <iostream>
#include <vector>
#include <map>

using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int left = 1;
    for (int i = 0; i < nums.size(); i++) {
        result[i]*=left;
        left*=nums[i];
    }
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        result[i]*=right;
        right*=nums[i];
    }
    
    return result;
}

int main()
{
    vector<int> nums{-1,1,0,-3,3};
    vector<int> ans = productExceptSelf(nums);
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}