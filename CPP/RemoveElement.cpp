#include <iostream>
#include <vector>

using namespace std;


int removeElement(vector<int>& nums, int val) {
    int currentIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[currentIndex++] = nums[i];
        }
    }
    return currentIndex;
}

int main()
{
    vector<int> nums{3,2,2,3};
    int val = 3;
    int result = removeElement(nums, val);
    for (auto& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    cout << "number of non val elements: " << result;
    return 0;
}