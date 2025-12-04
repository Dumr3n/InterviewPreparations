#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
    int val;
    vector<Node*> neighbours;
    Node() : val(0) {}
    Node(int val) : val(val) {}
    Node(int val, vector<Node*> neighbours) : val(val), neighbours(neighbours) {}
};


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses);

    for (const auto& i : prerequisites) {
        adj[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }
    
    queue<int> q;

    for (int i = 0; i < numCourses; i++) 
        if (indegree[i] == 0) 
            q.push(i);

    vector<int> ans;

    int visited = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        visited++;
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (visited == numCourses) {
        return ans;
    }

    return {};
}

int main()
{
    int numCourses{2};
    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    auto res = findOrder(numCourses, prerequisites);

    cout << "Ans is \n";
    for (const auto& i : res) 
        cout << i << " ";
    cout << endl;
    return 0;
};
