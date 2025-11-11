#include <iostream>
#include <vector>

using namespace std;

bool isSubsequence(string s, string t) {
    int sStart{0};
    int tStart{0};
    while (sStart < s.size() && tStart < t.size()) {
        if (s[sStart] == t[tStart]) 
            sStart++;
        tStart++;
    }
    return sStart == s.size();
}

int main()
{
    string s{"abc"};
    string t{"ahbgdc"};
    cout << "Is a subsequence? Ans: " << boolalpha << isSubsequence(s, t) << endl;
    return 0;
}