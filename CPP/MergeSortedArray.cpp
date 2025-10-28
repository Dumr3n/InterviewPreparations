#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int mEnd = m - 1;
    int nEnd = n - 1;
    int writeIndex = m + n - 1;
    while (mEnd >= 0 || nEnd >= 0) {
        if (nEnd < 0) {
            nums1[writeIndex--] = nums1[mEnd--];
            continue;
        }
        if (mEnd < 0 ) {
            nums1[writeIndex--] = nums2[nEnd--];
            continue;
        }
        nums1[writeIndex--] = nums1[mEnd] > nums2[nEnd] ? nums1[mEnd--] : nums2[nEnd--];
    }

}

int main()
{
    vector<int>nums1{2,0};
    int m = 1;
    vector<int>nums2{1};
    int n = 1;
    merge(nums1, m, nums2, n);
    for (auto& num : nums1)
        cout << num << " ";
    cout << endl;
    return 0;
}