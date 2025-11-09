#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join(const vector<string>& words, const string& s) {
    string joined;
    for (int i = 0; i < words.size(); i++) {
        joined += words[i];
        if (i != words.size()-1)
            joined += s;
    }
    return joined;
}

string adjust(string s, int width) {
    for (int i = 0; i < s.size() - width; i++) {
        s += " ";
    }
    return s;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    vector<string> row;
    int rowCount = 0;
    for (const auto & word : words) {
        if (rowCount + row.size() + word.size() > maxWidth) {
            const int spaces = maxWidth - rowCount;
            if (row.size() == 1) {
                for (int i = 0; i < spaces; i++) {
                    row[0] += " ";
                }
            } else {
                for (int i = 0; i < spaces; i++)
                    row[i % (row.size()-1)] += " ";
            }
            result.push_back(join(row, ""));
            row.clear();
            rowCount = 0;
        }
        row.push_back(word);
        rowCount += word.size();
    }
    result.push_back(adjust(join(row, " "), maxWidth));
    return result;
}
int main()
{
    int maxWidth = 16;
    vector<string> words{
        "This1111111111",
        "is",
        "an",
        "example", 
        "of", 
        "text", 
        "justification."   
    };
    vector<string> justifiedWords = fullJustify(words, maxWidth);
    for (const auto & string : justifiedWords)
        cout << string << endl;
    return 0;
}