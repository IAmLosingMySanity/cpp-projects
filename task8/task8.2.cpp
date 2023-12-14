#include <iostream>
#include <queue>
#include <unordered_set>

template <typename T>
bool containsDuplicateElements(std::queue<T>& q) {
    std::unordered_set<T> elements;
    
    while (!q.empty()) {
        T element = q.front();
        q.pop();
        
        if (elements.count(element) > 0) {
            return true;
        }
        
        elements.insert(element);
    }
    
    return false;
}

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    
    bool containsDuplicates = containsDuplicateElements(q);
    
    std::cout << "Contains duplicates: " << std::boolalpha << containsDuplicates << std::endl;
    
    return 0;
}