#include <iostream>
#include <vector>

void move_zeros(std::vector<int> &nums) {
    int i = 0;
    int j = 0;

    // the problem is kinda tricky for me to explain

    // instead of moving zeros we will move non-zero values to the left
    // j-th is the last placed number index + 1
    while (i < nums.size()) {
        if (nums[i] != 0) {
            std::swap(nums[i], nums[j]);
            j++;
        }
        i++;
    }

    // it's much clearer with a simple example like this:
    // [1, 2, 3, 0, 4]
    //
    // i = 0, j = 0
    // nums[i] is not zero, swap nums[0] with nums[0]
    // i = 1, j = 1
    // nums[i] is not zero, swap nums[1] with nums[1]
    // i = 2, j = 2
    // nums[i] is not zero, swap nums[2] with nums[2]
    // i = 3, j = 3
    // nums[i] is zero, go to the next i-th element, j in the case will be the last placed index number + 1, the place where we should put the next non-zero value
    // i = 4, j = 3
    // nums[i] is not zero, swap nums[4] with nums[3]
    // i = 4, j = 4
    // [1, 2, 3, 4, 0]
}

int main() {
    std::vector<int> nums = {0, 0, 1, 2, 3};
    move_zeros(nums);

    for (const auto &n : nums)
        std::cout << n << ", ";

    std::cout << std::endl;
    return EXIT_SUCCESS;
}
