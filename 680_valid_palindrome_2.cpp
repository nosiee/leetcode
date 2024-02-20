#include <string>

bool check(int l, int r, std::string &s) {
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            return false;
        }
    }

    return true;
}

bool validPalindrome(std::string s) {
    int l = 0;
    int r = s.length() - 1;

    // kinda similar problem to 125 Valid Palindrome, but a bit tricky
    while (l < r) {
        // use two pointer technique until we meet some two different character
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            // i think this line makes some sence. in other people solutions they're just call the check function and that's it.
            // but do we really need to keep checking the string, even if we meet two different characters and their neighboring characters are not the same
            // i mean:
            //
            // caba
            // in this c != a, but the next character from "c" is "a"
            // or
            // abac
            // same case but from the right side
            // if their neighboring characters are not the same, i think it means we have MORE than one character that we need to delete from the string to make it
            // palindrome. maybe im wrong, i dont know..
            // it works the same with or without this line so i will keep it anyway

            if (s[l] == s[r - 1] || s[l + 1] == s[r]) {

                // the main idea here is for cases like: caba, we dont actually know which character we need to delete, so we just try both cases
                if (check(l, r - 1, s) || check(l + 1, r, s)) {
                    return true;
                }

                return false;
            } else {
                return false;
            }
        }
    }

    return true;
}
