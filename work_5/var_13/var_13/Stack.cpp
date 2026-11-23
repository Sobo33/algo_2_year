#include "Stack.h"
#include <stdexcept>

Stack::Stack() {
    capacity = 4;
    count = 0;
    data = new int[capacity];
}

Stack::~Stack() {
    delete[] data;
}

void Stack::resize() {
    int newCapacity = capacity * 2;
    int* newData = new int[newCapacity];
    for (int i = 0; i < count; i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void Stack::push(int value) {
    if (count == capacity)
        resize();
    data[count] = value;
    count++;
}

int Stack::pop() {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    count--;
    return data[count];
}

int Stack::top() const {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    return data[count - 1];
}

bool Stack::isEmpty() const { return count == 0; }
int Stack::size() const { return count; }

void Stack::reverse() {
    for (int i = 0; i < count / 2; i++) {
        int temp = data[i];
        data[i] = data[count - 1 - i];
        data[count - 1 - i] = temp;
    }
}