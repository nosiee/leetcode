#include <iostream>
#include <vector>

int signFunc(const int n) {
    if (n > 0) return 1;
    if (n < 0) return -1;

    return 0;
}

int arraySign(std::vector<int> &nums) {
    int product = 1;
    
    // we can ignore the number itself and only use its sign
    for (const int &n: nums) {
       if (n == 0) return 0; 
       if (n > 0) product *= 1;
       if (n < 0) product *= -1;
    }

    // instead, we could look at the number of negatives in nums. 
    // if its even, the total product is positive and the opposide 
    return signFunc(product);
}
