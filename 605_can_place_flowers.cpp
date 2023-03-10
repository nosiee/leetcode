#include <iostream>
#include <vector>

bool can_place_flowers(std::vector<int>& flowerbed, int n) {
    // of course you can place zero flowers
    if (n == 0)
        return true;

    // the idea of using a "window" in three elements
    // but to do this we need to add an element at the beginning and end
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);

    for (int i = 1; i < flowerbed.size()-1; i++) {
        // if every number in the window is zero we can place a flower at index i
        // 0 0 0
        // we can place a flower at the beggining of the window
        // we can place a flower at the end of the window
        // and we can place a flower at the middle of the window
        if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
            // place flower at index i
            flowerbed[i] = 1;
            n--;
        }

        // repeat until all the flowers are placed
        if (n == 0)
            return true;
    }

    return false;
}
