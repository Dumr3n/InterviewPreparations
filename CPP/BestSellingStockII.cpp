#include <iostream>
#include <vector>
#include <map>

using namespace std;


int profitCalculate(vector<int>& prices) {
    int result{0};
    for (int i = 0; i < prices.size()-1;i++) {
        if (prices[i+1] > prices[i]) {
            result+=prices[i+1]-prices[i];
        }
    }

    return result;
}

int main()
{
    vector<int> prices{1,2,3,4,5};
    cout << "Max profit " << profitCalculate(prices) << endl;
    return 0;
}