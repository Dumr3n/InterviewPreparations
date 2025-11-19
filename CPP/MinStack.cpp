#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    vector<string> st;
    istringstream ss(path);
    string word;
    while (getline(ss, word, '/')) {
        if (word == "" || word == ".") {
            continue;
        }
        if (word == "..") {
            if (!st.empty()) {
                st.pop_back();
            }
        } else {
            st.push_back(word);
        }
    }
    ostringstream res;
    for (const string& s : st) {
        res << "/" << s;
    }
    return res.str().empty() ? "/" : res.str();
}

int main()
{
    string s{"/home/"};
    cout << "Output " << simplifyPath(s) << endl;
    return 0;
}