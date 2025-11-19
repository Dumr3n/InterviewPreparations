#include <iostream>
#include <vector>

using namespace std;

int calculate(string s) {
    long long res = 0;
    int sign = 1;
    stack<pair<int,int>> st;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            long long num = 0;
            while (i < s.size() && isdigit(s[i])){
                num = num * 10 + s[i] - '0';
                i++;
            }
            i--;
            res += num * sign;
            sign = 1;
        } else if (s[i] == '(') {
            st.push({res,sign});
            res = 0;
            sign = 1;
        } else if (s[i] == ')') {
            res = st.top().first + (st.top().second * res);
            st.pop();
        } else if (s[i] == '-') {
            sign = -1*sign;
        }
    }
    return res;
}

int main()
{

    string s{"1+1"};
    
    cout << "Result of evaluation " << calculate(s) << endl;
    return 0;
}