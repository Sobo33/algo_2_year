#pragma once

class Stack {
    int* data;
    int count;
    int capacity;
    void resize();

public:
    Stack();
    ~Stack();
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    int size() const;
    void reverse();
};