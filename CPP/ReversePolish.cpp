#include <iostream>
#include <vector>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
        string t = tokens[i];
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int secondOp = st.top();
            st.pop();
            int firstOp = st.top();
            st.pop();
            switch (t[0]) {
                case '+':
                    st.push(firstOp+secondOp);
                    break;
                case '-':
                    st.push(firstOp-secondOp);
                    break;
                case '*':
                    st.push(firstOp*secondOp);
                    break;
                case '/':
                    st.push(firstOp/secondOp);
                    break;
            }
        } else {
            st.push(stoi(t));
        }
    }
    return st.top();
}

int main()
{

    vector<string> tokens{"4","13","5","/","+"};
    
    cout << "Result of evaluation " << evalRPN(tokens) << endl;
    return 0;
}