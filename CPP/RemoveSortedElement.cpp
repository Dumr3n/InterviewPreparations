#include <iostream>
#include <vector>

using namespace std;


int removeElement(vector<int>& nums) {
    int currentIndex = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[currentIndex]) {
            nums[++currentIndex] = nums[i];
        }
    }
    return currentIndex + 1;
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