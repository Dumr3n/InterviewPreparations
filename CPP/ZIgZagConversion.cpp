#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
       if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        int idx = 0, d = 1;
        vector<vector<char>> rows(numRows);

        for (char c : s) {
            rows[idx].push_back(c);
            if (idx == 0) {
                d = 1;
            } else if (idx >= numRows - 1) {
                d = -1;
            }
            idx += d;
        }

        string result;
        for (const auto& row : rows) {
            for (char c : row) {
                result += c;
            }
        }

        return result; 
    return result;
}
int main()
{
    string s{"AB"};
    int numRows{1};

    cout << convert(s, numRows) << endl;
    return 0;
}