#include <iostream>
#include <vector>
#include <map>

using namespace std;


int profitCalculate(vector<int>& prices) {
    int firstPrice{prices[0]};
    int result = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (firstPrice > prices[i]) {
            firstPrice = prices[i];
        }
        if (result < prices[i] - firstPrice) {
            result = prices[i] - firstPrice;
        }
    }

    return result;
}

int main()
{
    vector<int> prices{7,1,5,3,6,4};
    cout << "Max profit " << profitCalculate(prices) << endl;
    return 0;
}