#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

string intToRoman(int i) {
    const vector<pair<string, int>> symMap{
        make_pair("I", 1),
        make_pair("IV", 4),
        make_pair("V", 5),
        make_pair("IX", 9),
        make_pair("X", 10),
        make_pair("XL", 40),
        make_pair("L", 50),
        make_pair("XC", 90),
        make_pair("C", 100),
        make_pair("CD", 400),
        make_pair("D", 500),
        make_pair("CM", 900),
        make_pair("M", 1000)
    };
    string result;
    auto it = symMap.crbegin();
    while (i > 0) {
        if (i - (*it).second >= 0) {
            result += (*it).first;
            i -= (*it).second;
        } else {
            it++;
        }
    }
    return result;
}

int main()
{
    int i{3749};

    cout << intToRoman(i) << endl;
    return 0;
}