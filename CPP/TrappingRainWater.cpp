#include <iostream>
#include <vector>
#include <map>

using namespace std;

int trap(vector<int>& heights) {
    int leftIndex{0};
    int rightIndex = heights.size()-1;
    int maxLeft{heights[leftIndex]};
    int maxRight{heights[rightIndex]};
    int result{0};

    while (leftIndex < rightIndex) {
        if (maxLeft < maxRight) {
            leftIndex++;
            maxLeft = max(maxLeft, heights[leftIndex]);
            result += maxLeft - heights[leftIndex];
        } else {
            rightIndex--;
            maxRight = max(maxRight, heights[rightIndex]);
            result += maxRight - heights[rightIndex];
        }
    }
    return result;
}

int main()
{
    vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Amount of water: " << trap(heights) << endl;
    return 0;
}