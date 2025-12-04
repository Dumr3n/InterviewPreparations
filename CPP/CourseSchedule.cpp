#include <iostream>
#include <unordered_map>
#include <unordered_set>
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

enum class Color {white, grey, black};

bool dfs(int course, vector<vector<int>>& adj, vector<Color>& colors) {
    colors[course] = Color::grey;
    
    for (int i : adj[course]) {
        if (colors[i] == Color::grey)
            return true;
        
        if (colors[i] == Color::white && dfs(i, adj, colors))
            return true;
    }

    colors[course] = Color::black;

    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.empty())
        return true;

    vector<vector<int>> adj(numCourses);

    for (const auto& i : prerequisites)
        adj[i[1]].push_back(i[0]);

    vector<Color> colors(numCourses, Color::white);

    for (int course = 0; course < numCourses; course++)
        if (colors[course] == Color::white && dfs(course, adj, colors))
            return false;

    return true;
}

int main()
{
    int numCourses{2};
    vector<vector<int>> prerequisites = {
        {1, 0}
    };


    cout << "Ans is " << boolalpha << canFinish(numCourses, prerequisites) << endl;
    return 0;
};
