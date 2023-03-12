#include <vector>

int majority_element(std::vector<int>& nums) {
    // since "You may assume that the majority element always exists"
    // the idea is that, if we meet the number again, we increment count
    // if the number is different we decrement count
    // because the majority element will definitely be in the array
    // it is obvious that the count will increase by the number of the majority element

    // for example
    // [2, 2, 2, 2, 1, 1, 1]
    // we increment count 4 times, and decrement 3 times
    // but the order of the numbers doesn't really matter
    // [2, 2, 1, 1, 1, 2, 2]
    // 
    // res = 2
    // count = 2
    // nums[1]
    //
    // res = 2
    // count = 1
    // nums[2]
    //
    // res = 2
    // count = 0
    // nums[3]
    //
    // res = 1
    // count = 1
    // nums[4]
    //
    // res = 1
    // count = 0
    // nums[5]
    //
    // res = 2
    // count = 1
    // nums[6]

    // take first number as a majority element
    int res = nums[0];
    // we meet that element once
    int count = 1;

    for (int i = 1, size = nums.size(); i < size; i++) {
        // if we meet different number we decrement count
        if (nums[i] != res) {
            if (count > 0) {
                count--;
            } else {
                // if count equal to zero, we change the potential majority element
                res = nums[i];
                count = 1;
            }
        } else {
            count++;
        }
    }

    return res;
}
