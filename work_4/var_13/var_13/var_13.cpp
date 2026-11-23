#include "SinglyLinkedList.h"
#include <iostream>

int main() {
    SinglyLinkedList<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(13);

    std::cout << "Initial list: ";
    list.print();
    std::cout << "Find 20: " << list.find(20) << '\n';
    std::cout << "Find 99: " << list.find(99) << '\n';

    std::cout << "Insert 25 after 20: " << list.insert_after(20, 25) << '\n';
    std::cout << "After insertion: ";
    list.print();

    std::cout << "Insert 40 after 30: " << list.insert_after(30, 40) << '\n';
    std::cout << "After insertion at the end: ";
    list.print();

    std::cout << "Insert after missing value: " << list.insert_after(99, 100) << '\n';
    return 0;
}