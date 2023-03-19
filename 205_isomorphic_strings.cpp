#include <unordered_map>
#include <string>

bool is_isomorphic(std::string s, std::string t) {
    std::unordered_map<char, char> maps;
    std::unordered_map<char, char> mapt;

    // we simply map each i-th character with each j-th character, where i is the current s character, and j is the current t character
    // note that we map characters to each other, because string can be isomorphic if you just swap them
    // for example foo and bar are not isomorphic, but bar and foo are isomorphic
    
    // egg and add are isomorphic
    // e -> a
    // a -> e
    
    // g -> d
    // d -> g

    // g is mapped to the same character
    // g -> d
    // and d too
    // d -> g

    for (int i = 0; i < s.length(); i++) {
        // if s[i] in the map, and maps[s[i]] != t[i], means that we're mapping s[i] to a different character, and strings are not isomorphic
        if (maps.count(s[i]) > 0) {
            if (maps[s[i]] != t[i]) {
                return false;
            }
        }

        // if t[i] in the map, and mapt[t[i]] != s[i], means that we're mapping t[i] to a different character, and strings are not isomorphic
        if (mapt.count(t[i]) > 0) {
            if (mapt[t[i]] != s[i]) {
                return false;
            }
        }

        maps[s[i]] = t[i];
        mapt[t[i]] = s[i];
    }

    return true;
}
