#include <iostream>
#include <unordered_set>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.size() == 0)
        return res;

    for (int i = 0; i < nums.size();) {
        int start = nums[i];
        int j = i;
        while (j+1 < nums.size() && nums[j+1] == nums[j]+1)
            j++;
        if (start == nums[j])
            res.push_back(to_string(start));
        else 
            res.push_back(to_string(start)+"->"+to_string(nums[j]));
        i = j + 1;
    }
    return res;
}

int main()
{
    vector<int> nums{0,1,2,4,5,7};
    
    vector<string> res = summaryRanges(nums);
    for(const auto& s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}