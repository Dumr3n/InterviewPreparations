#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int start = 0;
    int end = citations.size() - 1;
    int result = 0;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if (citations[mid] >= citations.size() - mid) {
            if (result < citations.size() - mid) {
                result = citations.size() - mid;
            }
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return result;
}
int main()
{
    vector<int> citations{3,0,6,1,5};
    cout << "HIndex " << hIndex(citations) << endl;
    return 0;
}