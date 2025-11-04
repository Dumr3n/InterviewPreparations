#include <iostream>
#include <vector>
#include <map>

using namespace std;

void reverse(vector<int>& nums, int first, int last)
{
    while (first < last) {
        int tmp = nums[first];
        nums[first] = nums[last];
        nums[last] = tmp;
        first++;
        last--;
    }
}
void rotateArray(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums, 0, nums.size()-1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size()-1);
}

int main()
{
    vector<int> nums{-1,-100,3,99};
    int k = 2;
    rotateArray(nums, k);
    for (auto& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}