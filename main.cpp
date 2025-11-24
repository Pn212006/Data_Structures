#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int frontIndex;
    int backIndex;
    int count;

    void resize() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];

        for (int i = 0; i < count; i++) {
            newData[i] = data[(frontIndex + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCap;
        frontIndex = 0;
        backIndex = count;
    }

public:
    Queue(int size = 10) {
        capacity = size;
        data = new T[capacity];
        frontIndex = 0;
        backIndex = 0;
        count = 0;
    }

    ~Queue() {
        delete[] data;
    }

    void push(T value) {
        if (count == capacity) resize();
        data[backIndex] = value;
        backIndex = (backIndex + 1) % capacity;
        count++;
    }

    T pop() {
        if (count == 0) throw runtime_error("Queue is empty.");
        T value = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return value;
    }

    bool empty() const { return count == 0; }
    int size() const { return count; }
};

template <typename T>
class Quack {
private:
    T* data;
    int capacity;
    int frontIndex;
    int backIndex;
    int count;

    void resize() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];

        for (int i = 0; i < count; i++) {
            newData[i] = data[(frontIndex + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCap;
        frontIndex = 0;
        backIndex = count - 1;
    }

public:
    Quack(int size = 10) {
        capacity = size;
        data = new T[capacity];
        frontIndex = 0;
        backIndex = -1;
        count = 0;
    }

    ~Quack() {
        delete[] data;
    }

    void push_front(T value) {
        if (count == capacity) resize();
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = value;
        count++;
    }

    void push_back(T value) {
        if (count == capacity) resize();
        backIndex = (backIndex + 1) % capacity;
        data[backIndex] = value;
        count++;
    }

    T pop_front() {
        if (count == 0) throw runtime_error("Quack is empty.");
        T value = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return value;
    }

    T pop_back() {
        if (count == 0) throw runtime_error("Quack is empty.");
        T value = data[backIndex];
        backIndex = (backIndex - 1 + capacity) % capacity;
        count--;
        return value;
    }

    bool empty() const { return count == 0; }
    int size() const { return count; }
};

int main() {
    cout << "====== TESTING QUEUE ======\n";
    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue size: " << q.size() << "\n";

    cout << "Popping: " << q.pop() << "\n";
    cout << "Popping: " << q.pop() << "\n";

    q.push(40);
    q.push(50);

    cout << "Popping: " << q.pop() << "\n";
    cout << "Popping: " << q.pop() << "\n";
    cout << "Popping: " << q.pop() << "\n\n";

    cout << "====== TESTING QUACK ======\n";
    Quack<int> dq;

    dq.push_back(100);
    dq.push_back(200);
    dq.push_front(50);
    dq.push_front(25);

    cout << "Size: " << dq.size() << "\n";

    cout << "pop_front: " << dq.pop_front() << "\n";
    cout << "pop_back: " << dq.pop_back() << "\n";
    cout << "pop_front: " << dq.pop_front() << "\n";
    cout << "pop_back: " << dq.pop_back() << "\n";

    return 0;
}
