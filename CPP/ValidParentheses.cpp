#include <iostream>
#include <stack>
using namespace std;

bool isOpenBracket(char& c) {
    return (c == '(' || c == '{' || c == '[');
}

char getCorrespondingOpen(char& c) {
    switch (c) {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';
    }
}

bool isValid(string s) {
   stack<char> st;
    for (char c : s) {
        if (isOpenBracket(c))
            st.push(c);
        else {
            if (st.empty() || st.top() != getCorrespondingOpen(c))
                return false;
            else 
                st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s{"()[]{}"};
    cout << "Are parentheses valid " << boolalpha << isValid(s) << endl;
    return 0;
}