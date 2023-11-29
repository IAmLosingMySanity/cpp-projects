#include <iostream>

template <typename T>
class Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        data = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T element) {
        if (size >= capacity) {
            std::cout << "Queue is full. Element cannot be added." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        data[rear] = element;
        size++;
    }

    T dequeue() {
        if (size <= 0) {
            std::cout << "Queue is empty. Element cannot be removed." << std::endl;
            return T();
        }

        T element = data[front];
        front = (front + 1) % capacity;
        size--;

        return element;
    }

    bool containsDuplicateElements() {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (data[i] == data[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Queue<int> q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(2);

    bool containsDuplicates = q.containsDuplicateElements();

    std::cout << "Contains duplicates: " << std::boolalpha << containsDuplicates << std::endl;

    return 0;
}