#include <string>
#include <iostream>

int str_str(std::string haystack, std::string needle) {
    if (needle.length() == 0)
        return 0;

    if (needle.length() > haystack.length())
        return -1;
    
    // using sliding window technique, iterate through haystack and moving start window position by i
    // in inner loop iterate through needle and compare each haystack[i + j] char with needle[j]
    for (int i = 0; i < haystack.length(); i++) {
        for (int j = 0; j < needle.length(); j++) {
            // we reach the haystack end and didnt find a full substring
            if ((i + j) > haystack.length())
                return -1;

            // go to the next haystack symbol
            if (haystack[i + j] != needle[j])
                break;

            // we reach the needle.length() but didnt break the loop, so we found a full substring and return i index
            if ((j + 1) == needle.length())
                return i;
        }
    }

    return -1;
}
