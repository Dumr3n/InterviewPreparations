#include <iostream>
#include <unordered_set>
using namespace std;
    
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;

    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i++]);
    }
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < intervals.size()) {
        res.push_back(intervals[i++]);
    }
    return res;
}

int main()
{
    vector<vector<int>> intervals{{1,2},
                                  {3,5},
                                  {6,7},
                                  {8,10},
                                  {12,16}};
    vector<int> newInterval {4,8};
    
    vector<vector<int>> res = insert(intervals, newInterval);
    for (const auto& vec : res) {
        for (const auto & i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}