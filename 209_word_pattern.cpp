#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

bool word_pattern(std::string pattern, std::string s) {
    // pretty similar problem to https://leetcode.com/problems/isomorphic-strings/

    std::unordered_map<char, std::string> m1;
    std::unordered_map<std::string, char> m2;
    std::stringstream stream(s);
    std::string word;
    int i = 0;

    // split a string by space character, and map characters and words to each other
    while (getline(stream, word, ' ')) {
        if (m1.count(pattern[i]) > 0) {
            // if we've already added such a character and the word is different, then s does not match the pattern
            if (m1[pattern[i]] != word)
                return false; 
        } else {
            m1[pattern[i]] = word;
        }

        if (m2.count(word) > 0) {
            // if we've already added such a word and the character is different, then s does not match the pattern
            if (m2[word] != pattern[i])
                return false;
        } else {
            m2[word] = pattern[i];
        }

        i++;
    }

    return i == pattern.size();
}
