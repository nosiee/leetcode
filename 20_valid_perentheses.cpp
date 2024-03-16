#include <stack>
#include <string>

bool is_valid(std::string s) {
    std::stack<char> st;

    // the problem is pretty easy if you know how to stack works and how to use it
    for (int i = 0; i < s.size(); i++) {
        // push every open parentheses to the stack
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            // if the current symbol is a closed parentheses and we dont have any open on the stack
            // we can be sure that the whole s string is invalid
            if (st.size() == 0) {
                return false;
            }

            // if we have something on the stack, pop it
            char p = st.top();
            st.pop();

            // and check that parentheses match
            if (p == '(' && s[i] != ')') {
                return false;
            }
            if (p == '[' && s[i] != ']') {
                return false;
            }
            if (p == '{' && s[i] != '}') {
                return false;
            }
        }
    }

    // the string can be something like ((((() which is invalid but if we didn't check the size, we could return true because last two parentheses match
    return (st.size() == 0);
}
