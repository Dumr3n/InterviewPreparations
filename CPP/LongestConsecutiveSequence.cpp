#include <iostream>
#include <set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
     if (nums.size() < 2)
        return nums.size();
    
     set<int> map;
     for (auto i : nums) 
        map.insert(i);
    int maxLen = 0;
    int currLen = 1;
    auto it = map.begin();
    int currI = *it;
    it++;
    while (it != map.end()) {
        if (*it == currI+1) {
            currLen++;
        } else {
            maxLen = max(currLen, maxLen);
            currLen = 1;
        }
        currI = *it;
        it++;
    }
    return max(currLen, maxLen);
}
int main()
{
    vector<int> nums{9,1,4,7,3,-1,0,5,8,-1,6};
    
    cout << "Longest consecutive sequence length " << longestConsecutive(nums) << endl;
    return 0;
}