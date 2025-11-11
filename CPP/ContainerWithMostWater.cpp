#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int start{0};
    int end = height.size() - 1;
    int currentArea{0};
    while (end > start) {
        currentArea = max(currentArea, (end - start)*min(height[start], height[end]));
        if (height[end] < height[start]) 
            end--;
        else 
            start++;
    }
    return currentArea;
}

int main()
{
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << "Ans is " << maxArea(height) << endl;
    return 0;
}