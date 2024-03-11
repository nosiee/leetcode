#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    // it's more like sorting on the fly than merging..
    // but my idea was to start from the beginning and swap numbers if needed, because of the swap i need to set i to 0, and check the array again
    //
    // int i = 0;
    // int j = 0;

    // while (j < n) {
    //     if (nums1[i] == 0 && i >= m) {
    //         nums1[i] = nums2[j];
    //         i=0;
    //         j++;
    //         m++;

    //         continue;
    //     }

    //     if (nums1[i] <= nums2[j]) {
    //         i++;
    //         continue;
    //     }

    //     if (nums1[i] > nums2[j]) {
    //         std::swap(nums1[i], nums2[j]);
    //         i=0;
    //     }
    // }

    // [1, 2, 3, 0, 0, 0]
    // [2, 5, 6]
    //
    // we know that nums1 always have enough space for nums2, we also know that nums1[m-1] and nums2[n-1] the biggest numbers
    // this time we start from the end, from m and n
    //
    // we check the nums1[m-1] and nums2[n-1]
    // if the nums1[m-1] less than nums2[n-1], means that nums2[n-1] the biggest number in the merged array, so we put it in the m+n-1 position, and decrement n
    //
    // [1, 2, 3, 0, 0, 6] m = 3
    // [2, 5, 6] n = 2
    //
    // ...
    //
    // [1, 2, 3, 0, 5, 6] m = 3
    // [2, 5, 6] n = 1
    //
    // if the nums1[m-1] greater than nums1[n-1] we put the nums1[m-1] to m+n-1 positions and decrement m
    //
    // [1, 2, 3, 3, 5, 6] m = 2
    // [2, 5, 6] n = 1
    //
    // for the cases when nums1[m-1] equal to nums2[m-1] we can put any nums1[m-1]/nums2[n-1] to m+n-1 position, in this case i put nums2[n-1] and decrement n
    //
    // [1, 2, 2, 3, 5, 6] m = 2
    // [2, 5, 6] n = 0
    //
    // n is zero, so we end the loop
    //
    //
    // for the arrays like [2, 0], [1]. apply the first condition:
    // [2, 2] m = 0
    // [1] n = 1
    //
    // and then because m is zero now, we just simply put nums2[n-1] to the nums1[m+n-1] position in the else case
    while (n > 0) {
        if (m > 0 && nums1[m - 1] >= nums2[n - 1]) {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        } else {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
}
