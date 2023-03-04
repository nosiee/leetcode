#include <vector>
#include <unordered_map>

std::vector<int> two_sum(std::vector<int>& nums, int target) {
    // unordered_map is faster than hashmap, and it has a constant time in avarage
    std::unordered_map<int, int> map; 
    int x = 0;

    for (int i = 0, size = nums.size(); i < size; i++) {
        // x + nums[i] = target
        // x = target - nums[i]
        x = target - nums[i];

        // if x is already in the map, return index of the x and i
        if (map.count(x))
            return {i, map[x]};

        map[nums[i]] = i;
    }

    return { };
}
