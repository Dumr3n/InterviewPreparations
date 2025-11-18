#include <iostream>
#include <set>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end() && (i - map[nums[i]]) <= k) {
            return true;
        }
        map[nums[i]] = i;
    }
    return false;
}

int main()
{
    int target = 3;
    vector<int> nums{1,2,3,1};
    
    cout << boolalpha;
    cout << "Is containsNearbyDuplicate " << containsNearbyDuplicate(nums, target) << endl;
    return 0;
}