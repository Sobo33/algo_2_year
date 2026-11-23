#pragma once
#include "Observer.h"

template <typename T>
class ObservableList {
    struct Node {
        Observer<T>* observer;
        Node* next;
    };

    T value;
    Node* head;
    Node* tail;

public:
    // O(1)
    ObservableList(T initialValue) {
        value = initialValue;
        head = nullptr;
        tail = nullptr;
    }

    ObservableList(const ObservableList&) = delete;
    ObservableList& operator=(const ObservableList&) = delete;

    // O(n)
    ~ObservableList() {
        while (head != nullptr) {
            Node* old = head;
            head = head->next;
            delete old;
        }
    }

    // O(1)
    void addObserver(Observer<T>& observer) {
        Node* node = new Node;
        node->observer = &observer;
        node->next = nullptr;

        if (head == nullptr)
            head = node;
        else
            tail->next = node;
        tail = node;
    }

    // O(n)
    void setValue(T newValue) {
        value = newValue;
        Node* current = head;
        while (current != nullptr) {
            current->observer->update(value);
            current = current->next;
        }
    }

    // O(1)
    T getValue() const { return value; }
};