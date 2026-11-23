#include "Observable.h"
#include "ObservableList.h"
#include "Benchmark.h"
#include <iostream>

int main() {
    Observer<int> first;
    Observer<int> second;
    Observable<int> number(13);

    number.addObserver(first);
    number.addObserver(second);
    number.setValue(25);

    std::cout << "Observable value: " << number.getValue() << '\n';
    std::cout << "First observer: " << first.getValue() << '\n';
    std::cout << "Second observer: " << second.getValue() << '\n';

    number.setValue(40);
    std::cout << "After another change: " << first.getValue() << '\n';
    std::cout << "Notifications: " << first.getChanges() << '\n';

    Observer<double> decimalObserver;
    Observable<double> decimal(1.5);
    decimal.addObserver(decimalObserver);
    decimal.setValue(2.5);
    std::cout << "Double observer: " << decimalObserver.getValue() << '\n';

    Observer<int> listObserver;
    ObservableList<int> listNumber(0);
    listNumber.addObserver(listObserver);
    listNumber.setValue(13);
    std::cout << "List implementation: " << listNumber.getValue() << '\n';
    std::cout << "List observer: " << listObserver.getValue() << '\n';

    benchmark();
    return 0;
}