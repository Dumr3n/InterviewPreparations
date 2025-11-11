#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int start{0};
    int end = numbers.size() - 1;
    while (numbers[start]+numbers[end] != target) {
        if (numbers[start]+numbers[end] > target) {
            end--;
        } else {
            start++;
        }
    }
    return vector<int>{start+1, end+1};
}

int main()
{
    vector<int> numbers{2,7,11,15};
    int target{9};
    vector<int> res = twoSum(numbers, target);
    cout << "Ans is ";
    for (auto &i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}