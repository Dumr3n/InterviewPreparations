#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int slideWindow = words[0].size();
    int wordCount = words.size();
    unordered_map<string, int> map;
    for (auto & w : words) {
        map[w]++;
    }
    unordered_map<string, int> copyMap;
    for (int offset = 0; offset < slideWindow; offset++) {
        int start = offset;
        int count = 0;
        copyMap.clear();
        for (int currIndex = offset; currIndex + slideWindow <= s.size(); currIndex += slideWindow) {
            string currentSubs = s.substr(currIndex, slideWindow);
            if (map[currentSubs] > 0) {
                copyMap[currentSubs]++;
                count++;
                while (copyMap[currentSubs] > map[currentSubs]) {
                    string tmpWord = s.substr(start, slideWindow);
                    copyMap[tmpWord]--;
                    start += slideWindow;
                    count--;
                }
                if (count == wordCount) {
                    res.push_back(start);
                }
            } else {
                count = 0;
                start = currIndex + slideWindow;
                copyMap.clear();
            }  
        }
    }
    return res;
}
int main()
{
    string s{"aaaaaaaaaaaaaa"};
    vector<string> words{"aa","aa"};
    vector<int> ans = findSubstring(s, words);
    cout << "Ans is ";
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}