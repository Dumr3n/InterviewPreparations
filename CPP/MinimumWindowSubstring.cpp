#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> map;
    for(auto& c : t) {
        map[c]++;
    }
    int remChar = t.size();
    int min[2] = {0, INT_MAX};
    int start = 0;
    for (int currIndex = 0; currIndex < s.size(); currIndex++) {
        char ch = s[currIndex];
        if (map[ch] > 0) {
            remChar--;
        }
        map[ch]--;
        if (remChar == 0) {
            while (true) {
                char chTmp = s[start];
                if (map.find(chTmp) != map.end() && map[chTmp] == 0) {
                    break;
                }
                map[chTmp]++;
                start++;
            }

            if (currIndex - start < min[1] - min[0]) {
                min[0] = start;
                min[1] = currIndex;
            }

            map[s[start]]++;
            remChar++;
            start++;
        }
    }
    return min[1] >= s.size() ? "" : s.substr(min[0], min[1] - min[0]+1);
}

int main()
{
    string s{"ADOBECODEBANC"};
    string t{"ABC"};
    cout << "Ans is " << minWindow(s, t) << endl;

    return 0;
}