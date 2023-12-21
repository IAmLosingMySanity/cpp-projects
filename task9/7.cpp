#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Set {
private:
    std::vector<T> elements;

public:
    void add(const T& element) {
        if (contains(element)) {
            return;
        }

        elements.push_back(element);
    }

    void remove(const T& element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it); 
        }
    }

    Set<T> intersection(const Set<T>& other) const {
        Set<T> result;
        for (const auto& element : elements) {
            if (other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    Set<T> operator-(const Set<T>& other) const {
        Set<T> result;
        for (const auto& element : elements) {
            if (!other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    bool contains(const T& element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    friend void printSet(const Set<T>& set) {
        for (const auto& element : set.elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);

    Set<int> otherIntSet;
    otherIntSet.add(2);
    otherIntSet.add(3);
    otherIntSet.add(4);

    Set<int> intersectionSet = intSet.intersection(otherIntSet);
    std::cout << "Intersection: ";
    printSet(intersectionSet);

    Set<int> differenceSet = intSet - otherIntSet;
    std::cout << "Difference: ";
    printSet(differenceSet);

    Set<std::string> stringSet;
    stringSet.add("apple");
    stringSet.add("banana");
    stringSet.add("orange");

    Set<std::string> otherStringSet;
    otherStringSet.add("banana");
    otherStringSet.add("orange");
    otherStringSet.add("kiwi");

    Set<std::string> intersectionStringSet = stringSet.intersection(otherStringSet);
    std::cout << "Intersection: ";
    printSet(intersectionStringSet);

    Set<std::string> differenceSet1 = stringSet - otherStringSet;
    std::cout << "Difference: ";
    printSet(differenceSet1);
}