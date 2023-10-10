#include <string>
#include <unordered_map>

int max_number_of_balloons(std::string text) {
    std::unordered_map<char, int> freq;

    // count the frequency of characters in the string
    for (const char& letter: text) {
        if (letter == 'b' || letter == 'a' || letter == 'l' || letter == 'o' || letter == 'n') {
            if (freq.count(letter) > 0) freq[letter]++;
            else freq[letter] = 1;
        }
    }

    // if any character is missing return 0
    if (freq['b'] == 0 || freq['a'] == 0 || freq['l'] == 0 || freq['o'] == 0 || freq['n'] == 0)
        return 0;

    int balloons = freq['b'];

    // devide double character frequency by 2, this will give us the maximum possible number of ballooons
    freq['l'] /= 2;
    freq['o'] /= 2;

    // find the minimum number in the frequency
    for (auto const& v: freq) {
        if (v.second < balloons)
            balloons = v.second;
    }

    return balloons;
}
