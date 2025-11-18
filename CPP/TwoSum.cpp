#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end()) {
            return {i, map[target - nums[i]]};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums{2,7,11,15};
    int target = 9;
    
    cout << "Ans is ";
    for (const auto i : twoSum(nums, target)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}