#pragma once

class Queue {
    int* data;
    int head;
    int count;
    int capacity;
    void resize();

public:
    Queue();
    ~Queue();
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    void enqueue(int value);
    int dequeue();
    int front() const;
    bool isEmpty() const;
    int size() const;
    void rotate(int k);
};