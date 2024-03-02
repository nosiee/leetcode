#include <algorithm>
#include <vector>

int minumum_difference(std::vector<int> &nums, int k) {
    int min = 0;
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    // the idea is to use sliding window technique
    //
    // for example:
    // nums = {9, 4, 1, 7}, k = 2
    // sort({9, 4, 1, 7}) - {9, 7, 4, 1}
    // take a window with k nums: {(9, 7), 4, 1} and find the difference which is 9 - 7 = 2 in this case
    // it's obvious that each number on the left side of the window, is always the max number in this window
    // and the right number in the window is always the min number in this window

    for (int i = 0; (i + k - 1) < nums.size(); i++) {
        if (min && (nums[i] - nums[i + k - 1] < min)) {
            min = nums[i] - nums[i + k - 1];
        } else if (!min) {
            min = nums[i] - nums[i + k - 1];
        }
    }

    return min;
}
