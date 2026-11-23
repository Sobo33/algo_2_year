#pragma once
#include "Observable.h"
#include "ObservableList.h"
#include <chrono>
#include <iostream>

inline void benchmark() {
    int sizes[] = {10, 100, 1000};
    const int repeats = 10000;

    std::cout << "\nObservers, updates, array ms, list ms, notifications\n";
    for (int index = 0; index < 3; index++) {
        int count = sizes[index];
        Observer<int>* arrayObservers = new Observer<int>[count];
        Observer<int>* listObservers = new Observer<int>[count];
        Observable<int> arrayValue(0);
        ObservableList<int> listValue(0);

        // O(n)
        for (int i = 0; i < count; i++) {
            arrayValue.addObserver(arrayObservers[i]);
            listValue.addObserver(listObservers[i]);
        }

        // O(n * repeats)
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < repeats; i++)
            arrayValue.setValue(i);
        auto finish = std::chrono::steady_clock::now();
        double arrayTime = std::chrono::duration<double, std::milli>(finish - start).count();

        // O(n * repeats)
        start = std::chrono::steady_clock::now();
        for (int i = 0; i < repeats; i++)
            listValue.setValue(i);
        finish = std::chrono::steady_clock::now();
        double listTime = std::chrono::duration<double, std::milli>(finish - start).count();

        // O(n)
        long long notifications = 0;
        for (int i = 0; i < count; i++)
            notifications += arrayObservers[i].getChanges() + listObservers[i].getChanges();

        std::cout << count << ", " << repeats << ", " << arrayTime << ", "
                  << listTime << ", " << notifications << '\n';

        delete[] arrayObservers;
        delete[] listObservers;
    }
}