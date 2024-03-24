#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) { return this->binary_search(nums, target, 0, nums.size() - 1); }

    int binary_search(std::vector<int> &nums, int target, int left, int right) {
        if (left > right) {
            return left;
        }

        int mid = (right + left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // the array is sorted, so the binary search is most optimal solution here
        // for the base case when left is greater than right, we will return left. this may not be so obvious at first tho
        // we could end up in three possible cases:
        //
        // no matter what size array we have, we'll end up with an array of single number and left at that point will equal right
        // the first case where the single number is greater than target
        // the second case where the single number is less than target
        // and the third case where the single number is equal to target, see above
        //
        // [3], target = 2, left = 0, right = 0
        // [1], target = 2, left = 0, rigth = 0
        //
        // 3 > 2, left = 0, rigth = -1
        // the current number is greater than target, so we insert the target at index 0 and "move" 3 to the right
        // [2, 3]
        //
        // 1 < 2, left = 1, right = 0
        // the current number is less than target, so we insert the target at the nums.size() index
        // [1, 2]
        //
        // we're either insert the target at 0 index or at the end of the nums
        if (nums[mid] > target) {
            return binary_search(nums, target, left, mid - 1);
        }

        if (nums[mid] < target) {
            return binary_search(nums, target, mid + 1, right);
        }

        return -1;
    }
};
