#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "PriorityQueue.h"
#include <iostream>
#include <stdexcept>

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Stack size: " << stack.size() << '\n';
    std::cout << "Stack top before reverse: " << stack.top() << '\n';
    stack.reverse();
    std::cout << "Stack after reverse: ";
    while (!stack.isEmpty())
        std::cout << stack.pop() << ' ';
    std::cout << '\n';

    Queue queue;
    for (int i = 1; i <= 5; i++)
        queue.enqueue(i * 10);
    queue.rotate(2);
    std::cout << "Queue size: " << queue.size() << '\n';
    std::cout << "Queue front after rotate(2): " << queue.front() << '\n';
    std::cout << "Queue after rotate(2): ";
    while (!queue.isEmpty())
        std::cout << queue.dequeue() << ' ';
    std::cout << '\n';

    Deque deque;
    deque.push_front(20);
    deque.push_front(10);
    deque.push_back(30);
    deque.push_back(40);
    deque.removeAt(1);
    std::cout << "Deque size after removeAt(1): " << deque.size() << '\n';
    std::cout << "Deque front and back: " << deque.front() << ' ' << deque.back() << '\n';
    std::cout << "Removed from back: " << deque.pop_back() << '\n';
    std::cout << "Remaining deque: ";
    while (!deque.isEmpty())
        std::cout << deque.pop_front() << ' ';
    std::cout << '\n';

    int values[] = {4, 13, 7, 1, 20, 9};
    PriorityQueue priority;
    priority.heapify(values, 6);
    std::cout << "Heap top: " << priority.top() << '\n';
    priority.push(25);
    std::cout << "Priority queue size: " << priority.size() << '\n';
    std::cout << "Priority queue: ";
    while (!priority.isEmpty())
        std::cout << priority.pop() << ' ';
    std::cout << '\n';

    try {
        stack.pop();
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    try {
        queue.dequeue();
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    try {
        deque.pop_front();
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    try {
        priority.pop();
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    return 0;
}