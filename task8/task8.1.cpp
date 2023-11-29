#include <iostream>

template <typename T>
class Queue {
private:
    T* data; // Массив для хранения элементов очереди
    int front; // Индекс начала очереди
    int rear; // Индекс конца очереди
    int capacity; // Вместимость очереди
    int size; // Текущий размер очереди

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
            std::cout << "Очередь полна. Невозможно добавить элемент." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        data[rear] = element;
        size++;
    }

    T dequeue() {
        if (size <= 0) {
            std::cout << "Очередь пуста. Невозможно удалить элемент." << std::endl;
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