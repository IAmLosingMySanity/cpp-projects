#include <iostream>

template <typename T>
class Set {
private:
    T* elements;
    int size;
    int capacity;

public:
    Set() {
        size = 0;
        capacity = 10;
        elements = new T[capacity];
    }

    ~Set() {
        delete[] elements;
    }

    void add(const T& element) {
        if (contains(element)) {
            return;
        }

        if (size == capacity) {
            resize();
        }

        elements[size++] = element;
    }

    void remove(const T& element) {
        int index = findIndex(element);
        if (index != -1) {
            for (int i = index; i < size - 1; i++) {
                elements[i] = elements[i + 1];
            }
            size--;
        }
    }

    Set<T> intersection(const Set<T>& other) {
        Set<T> result;
        for (int i = 0; i < size; i++) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    Set<T> operator-(const Set<T>& other) {
        Set<T> result;
        for (int i = 0; i < size; i++) {
            if (!other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    bool contains(const T& element) const {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    int findIndex(const T& element) const {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    friend void printSet(const Set<T>& set) {
        for (int i = 0; i < set.size; i++) {
            std::cout << set.elements[i] << " ";
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
    printSet(intersectionSet);  // Выведет: 2 3

    Set<int> differenceSet = intSet - otherIntSet;
    std::cout << "Difference: ";
    printSet(differenceSet);  // Выведет: 1

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
}