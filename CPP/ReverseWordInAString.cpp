#include <iostream>
#include <string>
#include <vector>

using namespace std;


string reverseWords(string s) {
    string result;
    int currIndex = s.size() - 1;
    while (currIndex >= 0) {
        if (s[currIndex] == ' ') {
            currIndex--;
            continue;
        }
        int start = currIndex--;
        while (currIndex >= 0 && s[currIndex] != ' ')
            currIndex--;
        if (result.size() != 0) {
            result += ' ';
        }
        result+=s.substr(currIndex+1, start - currIndex);
    }
    return result;
}
int main()
{
    string s{"a good   example"};

    cout << reverseWords(s) << endl;
    return 0;
}