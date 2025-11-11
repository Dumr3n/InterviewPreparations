#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    sort(nums.begin(),nums.end());
    if (nums[0] > 0)
        return {};
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        hash[nums[i]] = i;
    }
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] > 0) {
            break;
        }
        for (int j = i + 1; j < nums.size() - 1; j++) {
            int needed = -1*(nums[i]+nums[j]);
            if (hash.count(needed) && hash.find(needed)->second > j) {
                ans.push_back({nums[i], nums[j], hash.find(needed)->first});
            }
            j = hash.find(nums[j])->second;
        }
        i = hash.find(nums[i]) -> second;
    }
    return ans;
}

int main()
{
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    cout << "Ans is \n";
    for (auto& container : res) {
        for (auto& i : container) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}