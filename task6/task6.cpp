#include <iostream>
#include <set>

class Set {
private:
    std::set<int> elements;

public:
    Set() {}

    ~Set() {}

    void addElement(int element) {
        elements.insert(element);
    }

    void removeElement(int element) {
        elements.erase(element);
    }

    std::set<int> intersection(const Set& otherSet) {
        std::set<int> result;
        for (int element : elements) {
            if (otherSet.elements.count(element) > 0) {
                result.insert(element);
            }
        }
        return result;
    }

    Set operator-(const Set& otherSet) {
        Set result;
        for (int element : elements) {
            if (otherSet.elements.count(element) == 0) {
                result.addElement(element);
            }
        }
        return result;
    }

    friend void printSet(const Set& set);
};

void printSet(const Set& set) {
    for (int element : set.elements) {
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
    printSet(set1);

    std::cout << "Set 2: ";
    printSet(set2);

    std::cout << "Intersection: ";
    std::set<int> intersection = set1.intersection(set2);
    for (int element : intersection) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Difference: ";
    Set difference = set1 - set2;
    printSet(difference);

    return 0;
}