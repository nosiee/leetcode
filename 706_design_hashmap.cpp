#include <vector>
#include <iostream>

// pretty simular to https://leetcode.com/problems/design-hashset/
// nothing to comment
class MyHashMap {
    private:
        std::vector<int> values;

    public:
        void put(int key, int value) {
            const int latest = this->values.size();

            if (key >= this->values.size()) {
                this->values.resize(key + 1);
                fill(this->values.begin() + latest, this->values.end(), -1);
            }

            this->values[key] = value;
        }

        int get(int key) {
            if (key < this->values.size())
                return this->values[key];

            return -1;
        }

        void remove(int key) {
            if (key < this->values.size())
                this->values[key] = -1;
        }
};

