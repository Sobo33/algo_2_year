#pragma once

class Deque {
    struct Node {
        int value;
        Node* previous;
        Node* next;
    };
    Node* head;
    Node* tail;
    int count;

public:
    Deque();
    ~Deque();
    Deque(const Deque&) = delete;
    Deque& operator=(const Deque&) = delete;

    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int front() const;
    int back() const;
    bool isEmpty() const;
    int size() const;
    void removeAt(int index);
};
