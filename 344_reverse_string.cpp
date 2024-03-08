#include <iostream>
#include <utility>
#include <vector>

void reverse(std::vector<char> &s) {
    int end = s.size() - 1;

    for (int start = 0; start < end; start++, end--) {
        std::swap(s[start], s[end]);
    }
}
