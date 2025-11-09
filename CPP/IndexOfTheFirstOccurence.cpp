#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {
    for (int i = 0; i <= static_cast<int>(haystack.size()) - static_cast<int>(needle.size()); i++) {
        if (haystack.substr(i, needle.size()) == needle) {
            return i;
        }
    }
    return -1;
}
int main()
{
    string haystack{"aaa"};
    string needle{"aaaa"};

    cout << strStr(haystack, needle) << endl;
    return 0;
}