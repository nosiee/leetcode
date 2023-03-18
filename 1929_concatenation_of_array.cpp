#include <vector>

std::vector<int> get_concatination(std::vector<int>& nums) {
    // O(n) in-place solution
    for (int i = 0, size = nums.size(); i < size; i++) {
        // just add every nums[i] number to the end
        nums.push_back(nums[i]);
    }

    return nums;
}
