#include <iostream>
#include <vector>
#include <unordered_map>


std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    if (nums.size() == 1) {
        result.push_back({nums[0]});
        return result;
    }

    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        std::vector<int> remain;
        for (int j = 0; j < nums.size(); j++) {
            if (j != i)
                remain.push_back(nums[j]);
        }
        std::vector<std::vector<int>> perms = permute(remain);
        for (std::vector<int> p : perms) {
            p.insert(p.begin(), n);
            result.push_back(p);
        }
        
    }
    return result;
}

int main()
{

    std::vector<int> nums{1, 2, 3};
    auto result = permute(nums);

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
