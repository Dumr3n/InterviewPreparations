#include <iostream>
#include <vector>
#include <map>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int currentTank = 0;
    bool exitFlag=false;
    for (int i = 0; i < gas.size(); i++) {
        currentTank = gas[i];
        exitFlag = false;
        for (int j = 0; j < gas.size(); j++) {
            int currentIndex = (i + j) % gas.size();
            currentTank -= cost[currentIndex];
            if (currentTank < 0) {
                exitFlag = true;
                break;
            }
            currentTank += gas[(currentIndex+1)%gas.size()];
        }
        if (!exitFlag)
            return i;
    }
    
    return -1;
}

int main()
{

    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}