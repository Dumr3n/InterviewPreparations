#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> hashMap;
    int start{0};
    int maxLen{0};
    for (int i = 0; i < s.size(); i++) {
        while (hashMap.count(s[i])) {
            hashMap.erase(s[start]);
            start++;
        }
        hashMap.insert(s[i]);
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int main()
{
    string s{" "};
    cout << "Ans is " << lengthOfLongestSubstring(s) << endl;
    return 0;
}