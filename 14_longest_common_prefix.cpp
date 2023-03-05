#include <vector>
#include <string>

std::string longest_common_prefix(std::vector<std::string>& strs) {
    std::string lcp;

    // take the first word
    for (int i = 0, isize = strs[0].length(); i < isize; i++) {
        // start from the second word 
        for (int k = 1, ksize = strs.size(); k < ksize; k++) {
            // and compare every [i]-th character of the first word with the [i]-th of the k-th word

            // if they're not equal, return longest common prefix
            if (strs[0][i] != strs[k][i])
                return lcp;
        }

        // add [i]-th character to longest common prefix, since the character is in all words
        lcp += strs[0][i];
    }

    return lcp;
}
