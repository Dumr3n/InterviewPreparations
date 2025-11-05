#include <iostream>
#include <vector>
#include <map>

using namespace std;


int calculateJump(vector<int>& nums) {
    int near{0}, far{0}, jumps{0};
    while (far < nums.size() - 1) {
        int fartherst{0};
        for (int i = near; i <= far; i++) {
            if (i+nums[i] > fartherst) {
                fartherst = i+nums[i];
            }
        }
        near = far + 1;
        far = fartherst;
        jumps++;
    }

    return jumps;
}

int main()
{
    vector<int> nums{2,3,1,1,4};
    cout << "Number of jumps " << calculateJump(nums) << endl;
    return 0;
}