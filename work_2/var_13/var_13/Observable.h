#pragma once
#include "Observer.h"
#include <stdexcept>

template <typename T>
class Observable {
    T value;
    Observer<T>* observers[1000];
    int count;

public:
    // O(1)
    Observable(T initialValue) {
        value = initialValue;
        count = 0;
    }

    // O(1)
    void addObserver(Observer<T>& observer) {
        if (count == 1000)
            throw std::out_of_range("Too many observers");
        observers[count] = &observer;
        count++;
    }

    // O(n)
    void setValue(T newValue) {
        value = newValue;
        for (int i = 0; i < count; i++)
            observers[i]->update(value);
    }

    // O(1)
    T getValue() const { return value; }
};