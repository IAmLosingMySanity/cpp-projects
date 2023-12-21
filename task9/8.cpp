#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    
    // Lambda expression to check for duplicate elements in the queue
    auto containsDuplicateElements = [](std::queue<int>& q) {
        std::unordered_set<int> elements;
        
        while (!q.empty()) {
            int element = q.front();
            q.pop();
            
            if (elements.count(element) > 0) {
                return true;
            }
            
            elements.insert(element);
        }
        
        return false;
    };
    
    bool containsDuplicates = containsDuplicateElements(q);
    
    std::cout << "Contains duplicates: " << std::boolalpha << containsDuplicates << std::endl;
    
    return 0;
}