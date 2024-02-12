#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> find_difference(const std::vector<int> &n1, const std::vector<int> &n2) {
    std::vector<int> a1;
    std::vector<int> a2;

    // initialize two sets of unique numbers
    std::unordered_set<int> s1(n1.begin(), n1.end());
    std::unordered_set<int> s2(n2.begin(), n2.end());

    // if number from the first list is not set s2, add it to a1
    for (const int n : s1) {
        if (s2.count(n) == 0)
            a1.push_back(n);
    }

    // if number from the second list is not set s1, add it to a1
    for (const int n : s2) {
        if (s1.count(n) == 0)
            a2.push_back(n);
    }

    return {a1, a2};
}
