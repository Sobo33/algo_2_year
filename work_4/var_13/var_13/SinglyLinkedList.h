#pragma once
#include <iostream>

template <typename T>
class SinglyLinkedList {
    struct Node {
        T value;
        Node* next;
    };
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* old = head;
            head = head->next;
            delete old;
        }
    }

    void push_front(T value) {
        Node* node = new Node;
        node->value = value;
        node->next = head;
        head = node;
    }

    bool find(T value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value)
                return true;
            current = current->next;
        }
        return false;
    }

    bool insert_after(T key, T value) {
        Node* current = head;
        while (current != nullptr && current->value != key)
            current = current->next;

        if (current == nullptr)
            return false;

        Node* node = new Node;
        node->value = value;
        node->next = current->next;
        current->next = node;
        return true;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << ' ';
            current = current->next;
        }
        std::cout << '\n';
    }
};