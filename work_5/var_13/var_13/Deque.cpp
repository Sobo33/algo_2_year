#include "Deque.h"
#include <stdexcept>

Deque::Deque() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

Deque::~Deque() {
    while (!isEmpty())
        pop_front();
}

void Deque::push_front(int value) {
    Node* node = new Node;
    node->value = value;
    node->previous = nullptr;
    node->next = head;

    if (head != nullptr)
        head->previous = node;
    else
        tail = node;
    head = node;
    count++;
}

void Deque::push_back(int value) {
    Node* node = new Node;
    node->value = value;
    node->previous = tail;
    node->next = nullptr;

    if (tail != nullptr)
        tail->next = node;
    else
        head = node;
    tail = node;
    count++;
}

int Deque::pop_front() {
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    Node* old = head;
    int value = old->value;
    head = head->next;

    if (head != nullptr)
        head->previous = nullptr;
    else
        tail = nullptr;

    delete old;
    count--;
    return value;
}

int Deque::pop_back() {
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    Node* old = tail;
    int value = old->value;
    tail = tail->previous;

    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;

    delete old;
    count--;
    return value;
}

int Deque::front() const {
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    return head->value;
}

int Deque::back() const {
    if (isEmpty())
        throw std::out_of_range("Deque is empty");
    return tail->value;
}

bool Deque::isEmpty() const { return count == 0; }
int Deque::size() const { return count; }

void Deque::removeAt(int index) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Invalid index");
    if (index == 0) {
        pop_front();
        return;
    }
    if (index == count - 1) {
        pop_back();
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;

    current->previous->next = current->next;
    current->next->previous = current->previous;
    delete current;
    count--;
}