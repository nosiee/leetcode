#include <vector>

class NumArray {
    public:
        NumArray(std::vector<int>& nums) {
            // add first number to the prefix sum array
            this->prefixSum.push_back(nums[0]);

            // add prefix sum to the prefix sum array
            // for example
            // nums: [1, 2, 3, 4, 5]
            // prefixSum: [1]
            //
            // [1, 1+2]
            // [1, 1+2, 1+2+3]
            // [1, 1+2, 1+2+3, 1+2+3+4]
            // [1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5]
            for (int i = 0; i < nums.size(); i++)
                this->prefixSum.push_back(nums[i] + this->prefixSum.back());
        }

        int sumRange(int left, int right) {
            // the range is inclusive
            // prefixSum[right] equal to sum of all numbers between 0 and right inclusive
            if (left == 0)
                return this->prefixSum[right];
            
            // for example we want to find a sum from 2 to 4
            // [1, 1+2, L(1+2+3), 1+2+3+4, R(1+2+3+4+5)]
            // result = R(1+2+3+4+5) - (1+2)
            // (1+2) in this case is the sum of all numbers up to L
            return this->prefixSum[right] - this->prefixSum[left-1];
        }

    private:
        std::vector<int> prefixSum;
};
