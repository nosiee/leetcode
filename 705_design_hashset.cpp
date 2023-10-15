#include <iostream>
#include <vector>

class MyHashSet {
    private:
        // we can be sure the keys are always numbers, so we can use a bool vector as a map
        std::vector<bool> values;

    public:
        void add(int key) {
            // allocate memory when we really need it
            if (key >= this->values.size())
                this->values.resize(key + 1);

            this->values[key] = true;
        }

        void remove(int key) {
            if (key < this->values.size()) {
                this->values[key] = false;
            }
        }

        bool contains(int key) {
            if (key < this->values.size()) {
                return this->values[key];
            }

            return false;
        }
};

