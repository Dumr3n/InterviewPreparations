#include <iostream>
#include <vector>
#include <map>

using namespace std;

int candy(vector<int>& ratings) {
    int candySum = ratings.size();
    int i = 1;
    while (i < ratings.size()) {
        if (ratings[i] == ratings[i - 1]) {
            i++;
            continue;
        }

        int currentCandy = 0;
        while (i < ratings.size() && ratings[i] > ratings[i-1]) {
            candySum += ++currentCandy;
            i++;
        }

        if (i == ratings.size()) {
            return candySum;
        }

        int currentValey = 0;
        while (i < ratings.size() && ratings[i] < ratings[i-1]) {
            candySum += ++currentValey;
            i++;
        }

        candySum -= min(currentCandy, currentValey);
    }
    return candySum;
    
}

int main()
{
    vector<int> ratings{2,4,6,7,3,2,2};
    
    cout << candy(ratings) << endl;
    return 0;
}