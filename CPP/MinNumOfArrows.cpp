#include <iostream>
#include <unordered_set>
using namespace std;
    
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
    auto prev = points[0][1];
    int res = 1;
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > prev) {
            res++;
            prev = points[i][1];
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> points{{9,12},
                               {1,10},
                               {4,11},
                               {8,12},
                               {3,9},
                               {6,9},
                               {6,7}};
    cout << "Min num of arrows is " << findMinArrowShots(points) << endl;
    return 0;
}