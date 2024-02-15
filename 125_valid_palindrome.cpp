#include <string>

bool is_palindrome(std::string s) {
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
        // if the symbol is not alpha or digit, go to the next symbol
        if (isalnum(s[l]) == false) {
            l++;
            continue;
        }

        // if the symbol is not alpha or digit, go to the next symbol
        if (isalnum(s[r]) == false) {
            r--;
            continue;
        }

        if (tolower(s[l]) == tolower(s[r])) {
            l++;
            r--;
        } else {
            return false;
        }
    }

    // we finish the loop when l == r, and we don't need to check the same symbol obviosly, but if l == r means we did't return with false and the string is palindrome
    // the second case when l > r, means we check all the symbol and didn't return with false so the string is palindrome as well
    return true;
}
