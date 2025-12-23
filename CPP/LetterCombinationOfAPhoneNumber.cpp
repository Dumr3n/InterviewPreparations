#include <iostream>
#include <vector>
#include <unordered_map>

void backtrack(std::string& digits, int idx, std::string word, std::vector<std::string>& result, const std::unordered_map<char, std::string>& map) {
    if (idx == digits.size()) {
        result.push_back(word);
        return;
    }

    std::string letters = map.at(digits[idx]);

    for (char letter : letters) {
        backtrack(digits, idx+1, word + letter, result, map);
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty())
        return {};

    std::unordered_map<char, std::string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    
    std::vector<std::string> result;
    
    backtrack(digits, 0, "", result, map);

    return result;
}

int main()
{

    std::string digits {"23"};
    std::vector<std::string> res = letterCombinations(digits);

    std::cout << "Ans is \n";
    for (const auto& i : res)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
};
