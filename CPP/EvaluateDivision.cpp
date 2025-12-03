#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

double divide(unordered_map<string, unordered_map<string, double>>& graph, const string A, const string B, unordered_set<string>&& seen) {
    if (A == B)
        return 1.0;
    
    seen.insert(A);

    for (const auto& [C, value] : graph.at(A)) {
        if (seen.contains(C))
            continue;
        
        const double res = divide(graph, C, B, std::move(seen));

        if (res > 0)
            return value * res;
    }

    return -1;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> ans;
    unordered_map<string, unordered_map<string, double>> graph;

    for (int i = 0; i < equations.size(); i++) {
        const string& A = equations[i][0];
        const string& B = equations[i][1];

        graph[A][B] = values[i];
        graph[B][A] = 1 / values[i];
    }

    for (const vector<string>& eq : queries) {
        const string& A = eq[0];
        const string& B = eq[1];

        if (!graph.contains(A) || !graph.contains(B)) {
            ans.push_back(-1);
        } else {
            ans.push_back(divide(graph, A, B, unordered_set<string>()));
        }
    }
    return ans;
}

int main()
{
    vector<vector<string>> equations {
        {"a","b"},
        {"b","c"}
    };

    vector<double> values {2.0, 3.0};

    vector<vector<string>> queries {
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };

    auto res = calcEquation(equations, values, queries);

    cout << "Ans is ";
    for (const auto& i : res)
        cout << i << " ";
    cout << endl;
    return 0;
};
