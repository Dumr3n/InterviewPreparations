#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n) {
    unordered_set<int> uset;
    int currNum = n;
    while(true) {
        vector<int> nums;
        while (currNum > 0 ) {
            nums.push_back(currNum % 10);
            currNum /= 10;
        }
        for (const auto& i : nums)
            currNum += pow(i,2);
        
        if (currNum == 1)
            return true;

        if (uset.find(currNum) != uset.end())
            return false;
        uset.insert(currNum);
    }
}

int main()
{
    int target = 9;
    
    cout << boolalpha;
    cout << "Is happy " << isHappy(target) << endl;
    return 0;
}