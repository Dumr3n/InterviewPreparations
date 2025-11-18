#include <iostream>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, int> SIndex;
    unordered_map<char, int> TIndex;
    for (int i = 0; i < s.size(); i++) {
        if (SIndex.find(s[i]) == SIndex.end())
            SIndex[s[i]] = i;
        if (TIndex.find(t[i]) == TIndex.end())
            TIndex[t[i]] = i;
        if (SIndex[s[i]] != TIndex[t[i]])
            return false;
    }
    return true;
}
int main()
{
    string s{"badc"};
    string t{"baba"};
    cout << boolalpha;
    cout << "Are they isomorphic " << isIsomorphic(s, t) << endl;
    return 0;
}