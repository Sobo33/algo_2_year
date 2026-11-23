#pragma once

class PriorityQueue {
    int* heap;
    int count;
    int capacity;
    void resize();
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    PriorityQueue();
    ~PriorityQueue();
    PriorityQueue(const PriorityQueue&) = delete;
    PriorityQueue& operator=(const PriorityQueue&) = delete;

    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    int size() const;
    void heapify(const int values[], int size);
};