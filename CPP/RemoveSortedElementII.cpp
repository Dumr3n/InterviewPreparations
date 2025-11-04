#include <iostream>
#include <vector>

using namespace std;


int removeElement(vector<int>& nums) {
    if (nums.size() <= 2)
        return nums.size();
    int currentIndex = 2;
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[currentIndex - 2]) {
            nums[currentIndex++] = nums[i];
        }
    }
    return currentIndex;
}

int main()
{
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int result = removeElement(nums);
    for (auto& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    cout << "number of non val elements: " << result;
    return 0;
}