#include <iostream>
#include <vector>
#include <unordered_map>

void backtrack(std::vector<std::vector<int>>& result, int start, const int k, const int n, std::vector<int>& number) {
    if (number.size() == k) {
        result.push_back(number);
        return;
    }

    for (int num = start; num <= n; num++) {
        number.push_back(num);
        backtrack(result, num + 1, k, n, number);
        number.pop_back();
    }

}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> number;
    backtrack(result, 1, k, n, number);

    return result;
}

int main()
{

    int n = 4;
    int k = 2;
    
    std::vector<std::vector<int>> result = combine(n, k);

    std::cout << "Ans is \n";
    for (const auto& i : result) {
        std::cout << "[";
        for (const auto& j : i)
            std::cout << j << " ";
        std::cout << "]\n";
    }
    std::cout << std::endl;
    return 0;
};
