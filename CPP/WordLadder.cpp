#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    if (wordSet.find(endWord) == wordSet.end())
        return 0;
    
    unordered_set<string> beginSet{beginWord};
    unordered_set<string> endSet{endWord};
    unordered_set<string> visited;
    int step{1};

    while(!beginSet.empty() && !endSet.empty()) {
        if (beginSet.size() > endSet.size())
            swap(beginSet, endSet);
        
        unordered_set<string> nextSet;

        for (const string& word : beginSet) {
            string current = word;
            
            for (int i = 0; i < current.size(); i++) {
                const char original = current[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) 
                        continue;
                    
                    current[i] = c;

                    if (endSet.count(current))
                        return step + 1;
                    
                    if (wordSet.count(current) && !visited.count(current)) {
                        visited.insert(current);
                        nextSet.insert(current);
                    }
                }
                current[i] = original;
            }
        }
        beginSet = nextSet;
        step++;
    }
    return 0;
}

int main()
{
    string beginWord{"hit"};
    string endWord{"cog"};
    vector<string> wordList {"hot","dot","dog","lot","log","cog"};
    cout << "Ans is " << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
};
