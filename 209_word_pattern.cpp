#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

bool word_pattern(std::string pattern, std::string s) {
    // pretty similar problem to https://leetcode.com/problems/isomorphic-strings/

    // at first, split the string by space 
    std::vector<std::string> words;
    std::stringstream stream(s);
    std::string word;
    
    while (getline(stream, word, ' ')) {
        words.push_back(word);
    }

    // the number of characters in the pattern must equal the number of words
    if (pattern.length() != words.size())
        return false;


    std::unordered_map<char, std::string> m1;
    std::unordered_map<std::string, char> m2;

    // map each word to each character in the pattern
    for (int i = 0, size = words.size(); i < size; i++) {
        if (m1.count(pattern[i]) > 0) {
            // if we've already added such a character and the word is different, then s does not match the pattern
            if (m1[pattern[i]] != words[i])
                return false; 
        } else {
            m1[pattern[i]] = words[i];
        }

        if (m2.count(words[i]) > 0) {
            // if we've already added such a word and the character is different, then s does not match the pattern
            if (m2[words[i]] != pattern[i])
                return false;
        } else {
            m2[words[i]] = pattern[i];
        }
    }

    return true;
}
