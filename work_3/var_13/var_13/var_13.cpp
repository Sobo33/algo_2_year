#include "Vector.h"
#include <iostream>

int main() {
    Vector<int> values;
    values.push_back(13);
    values.push_back(20);
    values.push_back(30);
    std::cout << "After push_back: ";
    values.print();

    values.pop_back();
    std::cout << "After pop_back: ";
    values.print();

    values.resize(5);
    std::cout << "After resize(5): ";
    values.print();

    values.resize(1);
    std::cout << "After resize(1): ";
    values.print();

    Vector<int> zeros(3);
    std::cout << "Vector with size 3: ";
    zeros.print();

    values.resize(0);
    try {
        values.pop_back();
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
    return 0;
}