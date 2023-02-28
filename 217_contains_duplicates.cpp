#include <unordered_set>
#include <vector>

bool contains_duplicates(std::vector<int>& nums) {
    // unordered_set is faster than hashmap, and it has a constant time in avarage
    std::unordered_set<int> set;

    for (int i = 0, size = nums.size(); i < size; i++) {
        // we've already added such a number, so nums has duplicates
        if (set.find(nums[i]) != set.end())
            return true;

        set.insert(nums[i]);
    }

    return false;
}
