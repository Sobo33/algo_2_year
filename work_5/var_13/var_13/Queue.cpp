#include "Queue.h"
#include <stdexcept>

Queue::Queue() {
    capacity = 4;
    count = 0;
    head = 0;
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::resize() {
    int newCapacity = capacity * 2;
    int* newData = new int[newCapacity];
    for (int i = 0; i < count; i++)
        newData[i] = data[(head + i) % capacity];
    delete[] data;
    data = newData;
    capacity = newCapacity;
    head = 0;
}

void Queue::enqueue(int value) {
    if (count == capacity)
        resize();
    int index = (head + count) % capacity;
    data[index] = value;
    count++;
}

int Queue::dequeue() {
    if (isEmpty())
        throw std::out_of_range("Queue is empty");
    int value = data[head];
    head = (head + 1) % capacity;
    count--;
    return value;
}

int Queue::front() const {
    if (isEmpty())
        throw std::out_of_range("Queue is empty");
    return data[head];
}

bool Queue::isEmpty() const { return count == 0; }
int Queue::size() const { return count; }

void Queue::rotate(int k) {
    if (k < 0)
        throw std::invalid_argument("Negative shift");
    if (isEmpty())
        return;
    k = k % count;

    for (int i = 0; i < k; i++) {
        int value = dequeue();
        enqueue(value);
    }
}