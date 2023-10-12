#include <iostream>
#include <vector>

class MyHashSet {
    private:
        // we can be sure the keys are always numbers, so we can use a bool vector as a map
        std::vector<bool> values;

    public:
        void add(int key) {
            if (key >= 0) {
                // allocate memory when we really need it
                if (key > this->values.size())
                    this->values.resize(key);

                this->values[key == 0 ? key : key - 1] = true;
            }
        }

        void remove(int key) {
            if (key >= 0 && key <= this->values.size()) {
                this->values[key == 0 ? key : key - 1] = false;
            }
        }

        bool contains(int key) {
            if (key >= 0 && key <= this->values.size()) {
                return this->values[key == 0 ? key : key - 1];
            }

            return false;
        }
};

