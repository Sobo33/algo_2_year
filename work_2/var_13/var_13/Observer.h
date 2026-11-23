#pragma once

template <typename T>
class Observer {
    T value;
    int changes;

public:
    // O(1)
    Observer() {
        value = T();
        changes = 0;
    }

    // O(1)
    void update(T newValue) {
        value = newValue;
        changes++;
    }

    // O(1)
    T getValue() const { return value; }

    // O(1)
    int getChanges() const { return changes; }
};