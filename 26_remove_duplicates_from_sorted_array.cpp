#include <iostream>
#include <vector>

int remove_duplicates(std::vector<int> &nums) {
    int k = 0;

    // we focus on the fact that the array is sorted
    // and no matter what will be after the k-th element
    for (int i = 0, size = nums.size(); i < size; i++) {

        // again, since the array is sorted, we can just check nums[i] number
        // with last moved nums[k] number, and if they're different, means that
        // nums[i] another unique number in the array
        // because the array is sorted, not unique numbers will always be follow each other
        //
        // [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
        // check nums[0] with nums[0]
        // 0 == 0
        // check nums[1] with nums nums[0]
        // 0 == 0
        // check nums[2] with nums[0]
        // 1 != 0
        // place nums[2] to nums[++k], because k=0 is unique anyways
        // [0, 1, 1, 1, 1, 2, 2, 3, 3, 4]
        // check nums[3] with nums[1]
        // 1 == 1
        // check nums[4] with nums[1]
        // 1 == 1
        // check nums[5] with nums[1]
        // 2 != 1
        // place nums[5] to nums[++k]
        // [0, 1, 2, 1, 1, 2, 2, 3, 3, 4]
        // and etc.

        if (nums[i] != nums[k]) {
            nums[++k] = nums[i];
        }
    }

    return k + 1;
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = remove_duplicates(nums);

    std::cout << k << std::endl;
    for (const auto &n : nums)
        std::cout << n << std::endl;
}
