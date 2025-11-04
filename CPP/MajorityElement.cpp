#include <iostream>
#include <vector>
#include <map>

using namespace std;


int majorityElement(vector<int>& nums) {
    int currentNum = nums[0];
    int currentFreq = 0;
    for (auto& i : nums) {
        if (i == currentNum) {
            currentFreq++;
        } else {
            currentFreq--;
            if (currentFreq == 0) {
                currentNum = i;
                currentFreq = 1;
            }
        }
    }
    return currentNum;
}

int main()
{
    vector<int> nums{3,2,3};
    int result = majorityElement(nums);
    for (auto& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    cout << "number of majority elements: " << result;
    return 0;
}