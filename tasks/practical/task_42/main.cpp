/*
 * Задание 42. Реализовать инкапсулированный счётчик.
 * Ввод: отсутствует.
 * Вывод: значение после двух вызовов increment, то есть 2.
 * Пример запуска: program -> 2.
 */
#include <iostream>

class Counter {
private:
    int value;

public:
    explicit Counter(int initial = 0) : value(initial) {}

    void increment() { ++value; }
    int getValue() const { return value; }
};

int main() {
    Counter counter;
    counter.increment();
    counter.increment();
    std::cout << counter.getValue() << '\n';
    return 0;
}
