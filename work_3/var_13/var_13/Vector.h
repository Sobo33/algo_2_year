#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
    T* data;
    int sz;
    int cap;

public:
    Vector() {
        data = nullptr;
        sz = 0;
        cap = 0;
    }

    Vector(int n) {
        if (n < 0)
            throw std::invalid_argument("Negative size");
        data = new T[n]{};
        sz = n;
        cap = n;
    }

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    ~Vector() {
        delete[] data;
    }

    void resize(int newSize) {
        if (newSize < 0)
            throw std::invalid_argument("Negative size");

        if (newSize > cap) {
            int newCap = cap;
            if (newCap == 0)
                newCap = 1;
            while (newCap < newSize)
                newCap *= 2;

            T* newData = new T[newCap];
            for (int i = 0; i < sz; i++)
                newData[i] = data[i];

            delete[] data;
            data = newData;
            cap = newCap;
        }

        for (int i = sz; i < newSize; i++)
            data[i] = T();
        sz = newSize;
    }

    void push_back(T value) {
        resize(sz + 1);
        data[sz - 1] = value;
    }

    void pop_back() {
        if (sz == 0)
            throw std::out_of_range("Vector is empty");
        sz--;
    }

    void print() const {
        for (int i = 0; i < sz; i++)
            std::cout << data[i] << ' ';
        std::cout << '\n';
    }
};
