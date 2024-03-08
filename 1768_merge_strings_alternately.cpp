#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

std::string merge(std::string w1, std::string w2) {
    // really ez problem, nothing to comment
    // the only thing is that i dont use the classic two pointers, as one is enough
    const size_t length = std::max(w1.length(), w2.length());
    std::string merged = "";

    for (int i = 0; i <= length; i++) {
        if (i < w1.length())
            merged += w1[i];
        if (i < w2.length())
            merged += w2[i];
    }

    return merged;
}
