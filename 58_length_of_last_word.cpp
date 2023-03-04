#include <string>

int length_of_last_word(std::string s) {
    int count = 0;

    // start at the end of the string
    for (int i = s.length()-1; i >= 0; i--)  {

        // increment count until s[i] is alpha
        if (isalpha(s[i])) count++;

        // if s[i] is space, and count more than zero, we found last word and return it length
        if (isspace(s[i]) && count > 0) return count;
    }

    return count;
}
