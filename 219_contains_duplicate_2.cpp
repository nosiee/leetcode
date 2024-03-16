#include <cmath>
#include <unordered_map>
#include <vector>

bool contains_nearby_duplicate(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> nm;

    // abs(i - j) <= actually a window size, which means that between i-th and j-th elements can't be more than k other elements
    for (int i = 0; i < nums.size(); i++) {

        // if we found a number that already exists in the map AND between i-th element and j-th element less or equal k elements, return true, we found such a pair
        if (nm.find(nums[i]) != nm.end() && abs(i - nm[nums[i]]) <= k) {
            return true;
        } else {
            // if the number didnt exists OR it does, but the window size is to large, we need to update the nums[i] index in the map
            // because there is no point to keep looking next
            nm[nums[i]] = i;
        }
    }

    return false;
}
