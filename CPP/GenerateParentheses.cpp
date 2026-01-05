#include <iostream>
#include <vector>

void dfs(int open, int close, std::string s, int n, std::vector<std::string>& res)
{
    if (close == open && close + open == 2*n) {
        res.push_back(s);
        return;
    }

    if (open < n)
        dfs(open + 1, close, s + "(", n, res);
    
    if (close < open)
        dfs(open, close + 1, s + ")", n, res);
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> res;
    dfs(0, 0, "", n, res);
    return res;
}

int main()
{

    int n = 3;
    auto res = generateParenthesis(n);

    std::cout << "Ans is\n";

    for (auto& str : res)
        std::cout << str << std::endl;

    return 0;
};
