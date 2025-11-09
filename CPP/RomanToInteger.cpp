#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int romanToInt(string s) {
    const unordered_map<char, int> symMap{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result{0};
    int tmpVal{symMap.at(s[0])};
    if (s.size() == 1) {
        return tmpVal; 
    }
    for (int i = 1; i < s.size(); i++) {
        if (symMap.at(s[i]) < symMap.at(s[i-1])) {
            result += tmpVal;
            tmpVal = symMap.at(s[i]);
            continue;
        }
        if (symMap.at(s[i]) > symMap.at(s[i-1])) {
            result += symMap.at(s[i]) - tmpVal;
            tmpVal = 0;
            continue;
        }
        tmpVal += symMap.at(s[i]);
    }
    if (tmpVal != 0) {
        result += tmpVal;
    }
    return result;
}

int main()
{
    string s{"MCMXCIV"};
    
    cout << romanToInt(s) << endl;
    return 0;
}