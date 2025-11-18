#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (auto& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto& vec : map) {
        res.push_back(vec.second);
    }
    return res;
}
int main()
{
    vector<string> strs {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    cout << "Ans is ";
    for (const auto& vects: res) {
        for (const auto& word : vects)
            cout << word << " ";
        cout << endl;
    }
    return 0;
}