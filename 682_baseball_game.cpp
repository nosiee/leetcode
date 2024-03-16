#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int cal_points(std::vector<std::string> &operations) {
    int points = 0;
    std::vector<int> stack;

    // kinda easy problem, nothing to comment
    for (int i = 0; i < operations.size(); i++) {
        const std::string operation = operations[i];

        if (operation != "C" && operation != "D" && operation != "+") {
            const int n = atoi(operation.c_str());

            stack.push_back(n);
            points += n;
        } else {
            if (operation == "C") {
                points -= stack.back();
                stack.pop_back();
            } else if (operation == "D") {
                points += stack.back() * 2;
                stack.push_back(stack.back() * 2);
            } else if (operation == "+") {
                const int s = (stack[stack.size() - 1] + stack[stack.size() - 2]);
                points += s;
                stack.push_back(s);
            }
        }
    }

    return points;
}
