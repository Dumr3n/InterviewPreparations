#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

class RandomizedSet {
    vector<int> arr;
    unordered_map<int, int> map;
public:
    RandomizedSet() {
    }

    bool search(int val) {
        return map.find(val) != map.end();
    }
    
    bool insert(int val) {
        if (!search(val)) {
            arr.push_back(val);
            map[val] = arr.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (search(val)) {
            auto it = map.find(val);
            arr[it->second] = arr.back();
            arr.pop_back();
            map[arr[it->second]] = it->second;
            map.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};


int main()
{
    int val = 42;
    RandomizedSet* obj = new RandomizedSet();
    obj->insert(1);
    obj->remove(2);
    obj->insert(2);
    obj->getRandom();
    obj->remove(1);
    obj->insert(2);
    obj->getRandom();
    
    return 0;
}