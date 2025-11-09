#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int start{0};
    int minSize{200};
    for (const auto& i : strs) {
        if (i.size() < minSize) {
            minSize = i.size();
        }
    }

    if (minSize == 0) return "";

    string result;
    for (int i = 0; i < minSize; i++) {
        char currentCh = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][i] != currentCh) {
                return result;
            }
        }
        result += currentCh;
    }
    return result;
}

int main()
{
    vector<string> s{
    "dog",
    "racecar",
    "car"};

    cout << longestCommonPrefix(s) << endl;
    return 0;
}