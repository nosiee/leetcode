#include <vector>

int find_pivot_index(std::vector<int>& nums) {
    int total = 0;
    int leftSum = 0;
    int rightSum = 0;

    // calculate a total sum of all elements in the nums
    for (auto n: nums)
        total += n;

    for (int i = 0, size = nums.size(); i < size; i++) {
        // [1,7,3,6,5,6] - total sum is 28
        // rightSum = 28 - current number and minus leftSum
        //
        // for example if i is 3
        // "delete" all elements from the left before the current number
        // [-, -, -, 6, 5, 6]
        //
        // "delete" current number
        // [-, -, -, -, 5, 6]
        // and the right sum is 11
        rightSum = total - nums[i] - leftSum;

        if (rightSum == leftSum)
            return i;

        // we add a new number to the sum after checking rigthSum == leftSum
        // for example i is 3
        // leftSum is 1+7+3 = 11, if we add a number before checking leftSum will be 17
        leftSum += nums[i];
    }

    return -1;
}
