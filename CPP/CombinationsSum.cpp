#include <iostream>
#include <vector>
#include <unordered_map>

void makeComb(std::vector<int>& candidates, int target, int idx, std::vector<int>& comb, int total, std::vector<std::vector<int>>&  result) {
    if (total == target) {
        result.push_back(comb);
        return;
    }
    
    if (total > target || idx >= candidates.size())
        return;
    
    comb.push_back(candidates[idx]);
    makeComb(candidates, target, idx, comb, total + candidates[idx], result);
    comb.pop_back();
    makeComb(candidates, target, idx + 1, comb, total, result);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> comb;
    makeComb(candidates, target, 0, comb, 0, result);
    return result;
}

int main()
{

    std::vector<int> candidates{2, 3, 6 ,7};
    int target = 7;
    auto result = combinationSum(candidates, target);

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
