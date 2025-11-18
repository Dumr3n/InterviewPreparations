#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool wordPattern(string pattern, string s) {
    if (pattern.size() - 1 != count(s.begin(), s.end(), ' '))
        return false;
    unordered_map<string, string> map;
    istringstream iss(s);
    string word;
    int index = -1;
    while (iss >> word) {
        index++;
        string keyP {"p_"};
        keyP += pattern[index];
        string keyW = "w_" + word;
        if (map.find(keyP) != map.end() && map[keyP] != word) return false;
        if (map.find(keyW) != map.end() && map[keyW][0] != pattern[index]) return false;
        map[keyP] = word;
        map[keyW] = pattern[index];
    }
    return true;
}

int main()
{
    string pattern{"abba"};
    string s{"dog cat cat dog"};
    cout << boolalpha;
    cout << "Are follow the same pattern " << wordPattern(pattern, s) << endl;
    return 0;
}