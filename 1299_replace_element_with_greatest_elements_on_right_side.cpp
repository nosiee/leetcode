#include <vector>

std::vector<int> replace_element(std::vector<int>& arr) {
    const int size = arr.size()-1;
    int max = -1;

    // [17, 18, 5, 4, 6, 1]
    // arr[0] = max(arr[1:6])
    // arr[1] = max(arr[2:6])
    // arr[2] = max(arr[3:6])
    // arr[3] = max(arr[4:6])
    // arr[4] = max(arr[5:6])
    // arr[5] = -1
    // the idea is to start at the end of the array.
    // find for the max number only between two elements, the current and the prev max number

    for (int i = size; i >= 0; i--) {
        // save the current number value
        int t = arr[i];
        // replace it with max number
        arr[i] = max;

        // update max number if needed
        if (t > max)
            max = t;
    }

    return arr;
}
