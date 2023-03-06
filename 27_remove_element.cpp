#include <vector>

int remove_element(std::vector<int>& nums, int val) {
    int k = 0;

    // since the order in the array is not important, we can use a slightly different idea
    for (int i = 0, size = nums.size(); i < size; i++) {
        // instead of moving numbers that equal val to the end, we can move number that NOT equal val to the beginning
        if (nums[i] != val) {
            // k-1 is the last != val number
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
