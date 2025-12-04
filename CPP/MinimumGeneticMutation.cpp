#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_map<string, int> map;
    
    for (const auto& gene : bank) 
        map[gene]++;

    queue<pair<string, int>> q;

    q.push({startGene, 0});

    while (!q.empty()) {
        auto tmp = q.front().first;
        int val = q.front().second;
        q.pop();

        if (tmp == endGene)
            return val;
        
        for (int i = 0; i < tmp.size(); i++) {
            char c = tmp[i];

            for (const char& ch : {'A', 'C', 'G', 'T'}) {
                tmp[i] = ch;

                if (map.count(tmp)) {
                    q.push({tmp, val+1});
                    map.erase(tmp);
                }
            }
            tmp[i] = c;
        }
    }
    return -1;

}

int main()
{
    string startGene{"AACCGGTT"};
    string endGene{"AACCGGTA"};
    vector<string> bank{"AACCGGTA","AACCGCTA","AAACGGTA"};

    cout << "Ans is " << minMutation(startGene, endGene, bank) << endl;

    return 0;
};
