#include <iostream>
#include <vector>
#include <map>

using namespace std;


bool calculateJump(vector<int>& nums) {
    int fartherst{0};
    for (int i = 0; i < nums.size(); i++) {
        if (i > fartherst) return false;
        if (i+nums[i] > fartherst) {
            fartherst = i+nums[i];
        }
    }
    return true;
}

int main()
{
    vector<int> nums{1,2,3,4,5};
    cout << "Could I reach the end " << (calculateJump(nums) ? "true" : "false") << endl;
    return 0;
}