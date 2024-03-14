#include <iostream>
#include <vector>

int max_profit(std::vector<int> &prices) {
    int max = 0;

    // b - buy
    // s - sell
    for (int b = 0, s = 1; s < prices.size();) {
        // pick a two numbers, if buy equal or more than sell then set b to s, because

        // if prices[b] >= prices[s] we dont need to keep looking at max profit for prices[b], because there is a number that less than prices[b], which will give as, much more profit
        // so we just set buy index to sell and go next
        if (prices[b] >= prices[s]) {
            b = s;
        } else {
            max = std::max(max, prices[s] - prices[b]);
        }

        // again, if we found such a number that prices[b] < prices[s] we CAN keep looking for the next max profit, until we meet something less than prices[b]
        s++;
    }

    return max;
}

int main() {
    std::vector<int> nums = {7, 1, 5, 0, 6, 4};
    std::cout << max_profit(nums) << std::endl;
}
