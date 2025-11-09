#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int posLastSpace = s.size()-1;
    while (posLastSpace >= 0 && s[posLastSpace] == ' ')
        posLastSpace--;
    int posLastChar{posLastSpace-1};
    while (posLastChar >= 0 && s[posLastChar] != ' ')
        posLastChar--;
    return posLastSpace - posLastChar;
}

int main()
{
    string s{"luffy is still joyboy"};

    cout << lengthOfLastWord(s) << endl;
    return 0;
}