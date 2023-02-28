#include <string>
#include <algorithm>

bool is_anagram(std::string s, std::string t) {
    if (s.length() != t.length())
        // valid anagrams cannot be of different sizes
        return false;

    // we assume that sorting has O(1) space complexity
    // std::sort(s.begin(), s.end());
    // std::sort(t.begin(), t.end());
    //
    // return s == t;


    // valid anagrams must have the same number of characters
    // using extra memory, two int arrays to keep track of the number of characters
    // where the array index is the character code minus 97('a')
    int smap[26] = {0};
    int tmap[26] = {0};

    for (int i = 0, size = s.length(); i < size; i++) {
        smap[s[i] - 97]++;
        tmap[t[i] - 97]++;
        // increment the number of characters, where the character index is s[i] - 97
    }

    // arrays must be the same
    for (int i = 0; i < 25; i++) {
        if (smap[i] != tmap[i])
            return false;
    }

    return true;
}
