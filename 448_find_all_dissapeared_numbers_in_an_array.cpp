#include <vector>
#include <cmath>

std::vector<int> find_dissapeared_numbers(std::vector<int>& nums) {
    std::vector<int> res;

    // each number in the nums array between [1, n]
    // the size of the nums array is n
    // to solve the problem with O(1) space and O(n) complexity
    // we can use the indexes of the nums array as flags, of which numbers are in the nums array and which are not
    //
    // for example: [4,3,2,7,8,2,3,1]
    // take the first number 4
    // and change the nums[4-1] number to negative = -7
    // it will be a flag that number 4 is present in the array
    //
    // take the second number 3
    // and change the nums[3-1] number to negative = -2
    // and repeat the process for each number, at the end we get an array
    // [-4, -3, -2, -7, 8, 2, -3, -1]
    // numbers 8 and 2 with indexes 4 and 5 are positive
    // so 4+1, and 5+1 are dissapeared numbers

    for (int i = 0; i < nums.size(); i++) {
        // take the first number
        int current_number = nums[i];

        if (nums[abs(current_number) - 1] > 0)
            // if it's a positive number, make it negative
            nums[abs(current_number)-1] *= -1;
    }

    // for each positive number, push the index+1 of the positive number to the result array
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            res.push_back(i+1);
    }

    return res;
}
