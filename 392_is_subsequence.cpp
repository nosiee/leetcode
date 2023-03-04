#include <string>

bool is_subsequence(std::string s, std::string t) {
    int i = 0;
    int j = 0;

    // use the two pointers technique
    // iterate until one of the pointers reaches the end of the string
    while (i < s.length() && j < t.length()) {
        // if characters are the same, move indexes next
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            // if not, move j to the next t character
            j++;
        }
    }

    // means that we have reached the end of the s subsequence, and we found all the characters in the t string
    if (i == s.length()) {
        return true;
    }

    // means that we have reached the end of the t string, and i not equal s.length()
    // so we checked all the characters, but did not find some
    // yeah, we could just return false, but it's more clearly
    if (j == t.length()) {
        return false;
    }

    return false;
}
