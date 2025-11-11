#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = nums.size();
    int start{0};
    int curSum{0};
    for (int end = 0; end < nums.size(); end++) {
        curSum += nums[end];
        while (curSum >= target) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
            }
            curSum -= nums[start];
            start++;
        }
    }
    return minLen != nums.size() ? minLen : 0;
}

int main()
{
    vector<int> nums{2,3,1,2,4,3};
    int target{7};
    cout << "Ans is " << minSubArrayLen(target, nums) << endl;
    return 0;
}