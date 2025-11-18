#include <iostream>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (auto c : magazine)
        map[c]++;
    for (auto c : ransomNote) {
        if (--map[c] < 0)
            return false;
    }
    return true;
}

int main()
{
    string ransomNote{"aa"};
    string magazine{"ab"};
    cout << boolalpha;
    cout << "Can construct " << canConstruct(ransomNote, magazine) << endl;
    return 0;
}