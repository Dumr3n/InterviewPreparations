#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> map;
    for (auto c : s) {
        map[c]++;
    }
    for (auto c : t) {
        if (--map[c] < 0)
            return false;
    }
    return true;
}

int main()
{
    string s{"anagram"};
    string t{"nagaram"};
    cout << boolalpha;
    cout << "Is anagram " << isAnagram(s, t) << endl;
    return 0;
}