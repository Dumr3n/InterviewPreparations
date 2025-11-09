#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isPalindrome(string s) {
    int startIndex = 0;
    int endIndex = s.size() - 1;
    while (startIndex <= endIndex) {
        if (!isalnum(s[startIndex])) {
            startIndex++;
            continue;
        }
        if (!isalnum(s[endIndex])) {
            endIndex--;
            continue;
        }
        if (tolower(s[startIndex]) != tolower(s[endIndex])) {
            return false;
        }
        startIndex++;
        endIndex--;
    }
    return true;
}

int main()
{
    string s{"a."};
    cout << "Is a palindrome? Ans: " << boolalpha << isPalindrome(s) << endl;
    return 0;
}