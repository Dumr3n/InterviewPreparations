#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
    vector<int> previous = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= previous[1]) {
            previous[1] = max(previous[1], intervals[i][1]);
        } else {
            res.push_back(previous);
            previous = intervals[i];
        }
    }
    res.push_back(previous);
    return res;
}

int main()
{
    vector<vector<int>> intervals {{8,10}
                                  ,{1,3}
                                  ,{15,18}
                                  ,{2,6}};
    
    vector<vector<int>> res = merge(intervals);
    cout << "Ans is \n";
    for (const auto & vec : res) {
        for (const auto & i : vec) {
            cout << i << " ";
        } 
        cout << endl;
    }
    return 0;
}