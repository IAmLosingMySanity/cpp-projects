#include <iostream>
#include <vector>

class Set {
private:
    std::vector<int> elements;

public:
    Set() {}

    ~Set() {}

    void addElement(int element) {
        elements.push_back(element);
    }

    void removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                break;
            }
        }
    }

    void insertBetween(int x, int element1, int element2) {
        auto it1 = std::find(elements.begin(), elements.end(), element1);
        auto it2 = std::find(elements.begin(), elements.end(), element2);
        if (it1 != elements.end() && it2 != elements.end()) {
            elements.insert(it2, x);
        }
    }

    std::vector<int> intersection(const Set& otherSet) {
        std::vector<int> result;
        for (int element : elements) {
            if (std::find(otherSet.elements.begin(), otherSet.elements.end(), element) != otherSet.elements.end()) {
                result.push_back(element);
            }
        }
        return result;
    }

    Set operator-(const Set& otherSet) {
        Set result;
        for (int element : elements) {
            if (std::find(otherSet.elements.begin(), otherSet.elements.end(), element) == otherSet.elements.end()) {
                result.addElement(element);
            }
        }
        return result;
    }
    
    std::vector<int> getElements() const {
        return elements;
    }
};

void printVector(const std::vector<int>& vec) {
    for (int element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    Set set1;
    set1.addElement(1);
    set1.addElement(2);
    set1.addElement(3);

    Set set2;
    set2.addElement(2);
    set2.addElement(3);
    set2.addElement(4);

    std::cout << "Set 1: ";
    printVector(set1.getElements());

    std::cout << "Set 2: ";
    printVector(set2.getElements());

    std::cout << "Intersection: ";
    std::vector<int> intersection = set1.intersection(set2);
    printVector(intersection);

    std::cout << "Difference: ";
    Set difference = set1 - set2;
    printVector(difference.getElements());

    return 0;
}