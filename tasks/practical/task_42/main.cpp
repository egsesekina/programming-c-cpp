/*
 * Задание 42. Реализовать инкапсулированный счётчик.
 * Ввод: начальное значение и число вызовов increment (0..1000000).
 * Вывод: итоговое значение счётчика.
 * Пример: 5 3 -> 8.
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
    int initial;
    int increments;
    if (!(std::cin >> initial >> increments) || increments < 0 ||
        increments > 1000000 || initial > 1000000000 ||
        initial < -1000000000 || initial > 1000000000 - increments) {
        std::cerr << "Error\n";
        return 1;
    }

    Counter counter(initial);
    for (int i = 0; i < increments; ++i) counter.increment();
    std::cout << counter.getValue() << '\n';
    return 0;
}
