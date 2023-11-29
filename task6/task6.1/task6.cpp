#include <iostream>
#include <array>
#include <algorithm>

class Set {
private:
    std::array<int, 100> elements; // Change the size as per your requirement

public:
    Set() {}

    ~Set() {}

    void addElement(int element) {
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == 0) {
                elements[i] = element;
                break;
            }
        }
    }

    void removeElement(int element) {
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == element) {
                elements[i] = 0;
                break;
            }
        }
    }

    void insertBetween(int x, int element1, int element2) {
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == element2) {
                for (int j = elements.size() - 1; j > i; --j) {
                    elements[j] = elements[j - 1];
                }
                elements[i] = x;
                break;
            }
        }
    }

    std::array<int, 100> intersection(const Set& otherSet) {
        std::array<int, 100> result;
        int index = 0;
        for (int element : elements) {
            if (std::find(otherSet.elements.begin(), otherSet.elements.end(), element) != otherSet.elements.end()) {
                result[index++] = element;
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

    std::array<int, 100> getElements() const {
        return elements;
    }
};

void printArray(const std::array<int, 100>& arr) {
    for (int element : arr) {
        if (element == 0) {
            break;
        }
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
    printArray(set1.getElements());

    std::cout << "Set 2: ";
    printArray(set2.getElements());

    std::cout << "Intersection: ";
    std::array<int, 100> intersection = set1.intersection(set2);
    printArray(intersection);
    std::cout << "Difference: ";
    Set difference = set1 - set2;
    printArray(difference.getElements());
}