#include "PriorityQueue.h"
#include <stdexcept>

PriorityQueue::PriorityQueue() {
    capacity = 4;
    count = 0;
    heap = new int[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

void PriorityQueue::resize() {
    int newCapacity = capacity * 2;
    int* newHeap = new int[newCapacity];
    for (int i = 0; i < count; i++)
        newHeap[i] = heap[i];
    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] >= heap[index])
            break;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void PriorityQueue::heapifyDown(int index) {
    while (2 * index + 1 < count) {
        int child = 2 * index + 1;
        if (child + 1 < count && heap[child + 1] > heap[child])
            child++;

        if (heap[index] >= heap[child])
            break;
        int temp = heap[index];
        heap[index] = heap[child];
        heap[child] = temp;
        index = child;
    }
}

void PriorityQueue::push(int value) {
    if (count == capacity)
        resize();
    heap[count] = value;
    count++;
    heapifyUp(count - 1);
}

int PriorityQueue::pop() {
    if (isEmpty())
        throw std::out_of_range("Priority queue is empty");
    int value = heap[0];
    heap[0] = heap[count - 1];
    count--;
    heapifyDown(0);
    return value;
}

int PriorityQueue::top() const {
    if (isEmpty())
        throw std::out_of_range("Priority queue is empty");
    return heap[0];
}

bool PriorityQueue::isEmpty() const { return count == 0; }
int PriorityQueue::size() const { return count; }

void PriorityQueue::heapify(const int values[], int size) {
    if (size < 0)
        throw std::invalid_argument("Negative size");
    while (capacity < size)
        resize();

    for (int i = 0; i < size; i++)
        heap[i] = values[i];
    count = size;

    for (int i = count / 2 - 1; i >= 0; i--)
        heapifyDown(i);
}