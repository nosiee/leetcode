#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

std::vector<int> next_greater_element(std::vector<int>& nums1, std::vector<int>& nums2) {
    // for some reason this solution beats 80%, around 6ms
    //std::vector<int> result;

    //// O(nums1.size)
    //for (int i = 0; i < nums1.size(); i++) {
        //// O(nums2.size)
        //// find nums1[i] in the subset
        //const int idx = std::find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();

        //// O(nums2.size)
        //// start from the idx index, find the first nums2[k] > nums[i] number
        //for (int k = idx; k < nums2.size(); k++) {
            //if (nums2[k] > nums1[i]) {
                //// add it to the result
                //result.push_back(nums2[k]);
                //break;
            //}

            //// if we've reached the end of the nums2
            //// means that we couldn't find a number > nums1[i]
            //if (k == nums2.size() - 1) {
                //// so just add -1
                //result.push_back(-1);
            //}
        //}
    //}

    //return result;


    // O(nums1.size + nums2.size) 
    std::unordered_map<int, int> nidx;
    std::vector<int> res;

    // make a map with the indexes
    for (int i = 0; i < nums1.size(); i++) {
        nidx[nums1[i]] = i;
        // and also -1 all numbers in result vector
        res.push_back(-1);
    }

    // the idea is based on the stack
    std::stack<int> stack;

    for (int i = 0; i < nums2.size(); i++) {
        // take a number 
        int current_number = nums2[i];

        // if stack is not empty and current_number greater that the stack.top()
        // means that we found the next greater element for stack.top()
        while (stack.size() && current_number > stack.top()) {
            // so we take the top
            int top = stack.top();
            
            // get it index in the map
            int idx = nidx[top];
            
            // remove top element for the stack
            stack.pop();

            // and place current_number in the res array by the idx index
            res[idx] = current_number;

            // until the stack is not empty, check each number on the stack, because for each element on the stack we probably found the greatest element
            // for example
            //
            // [2, 1, 3, 4]
            // 2 goes on the stack
            // 1 goes on the stack, since stack.top > 1
            // 3 is greater than stack.top(1), so for 1 the greatest element is 3
            // but it also greatest element for 2, so we check next element on the stack
    }

    // we don't need to add number that is not in the nums1 subset 
    if (nidx.count(current_number))
        stack.push(current_number);
    }

    return res;
}
