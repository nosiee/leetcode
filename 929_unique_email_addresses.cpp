#include <string>
#include <cstring>
#include <vector>
#include <set>

int num_unique_emails(std::vector<std::string>& emails) {
    std::set<std::string> unique_emails;

    for (int i = 0; i < emails.size(); i++) {
        const int plus = emails[i].find("+");
        int localnameEnd = emails[i].find("@");
        int dot = emails[i].find(".");

        // delete everything that comes after "+"
        if (plus > -1 && plus < localnameEnd) {
            emails[i].erase(plus, localnameEnd - plus);
        }

        // find a new @ index after erase 
        localnameEnd = emails[i].find("@");

        // delete every "." in the string
        while (dot != -1 && dot < localnameEnd) {
            emails[i].erase(dot, 1);
            dot = emails[i].find(".");
        }

        unique_emails.insert(emails[i]);
    }

    return unique_emails.size();
}
