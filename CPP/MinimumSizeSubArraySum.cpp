#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = nums.size() + 1;
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
    return minLen != nums.size() + 1 ? minLen : 0;
}

int main()
{
    vector<int> nums{1,1,1,1,1,1,1,1};
    int target{11};
    cout << "Ans is " << minSubArrayLen(target, nums) << endl;
    return 0;
}