/*
 * Задание 11. Показать динамический полиморфизм через virtual и override.
 * Ввод: целое число.
 * Вывод: удвоенное число через вызов виртуального метода.
 * Пример: 7 -> 14.
 */
#include <iostream>

class Operation {
public:
    virtual int apply(int value) const = 0;
    virtual ~Operation() = default;
};

class DoubleOperation final : public Operation {
public:
    int apply(int value) const override { return value * 2; }
};

int main() {
    int value;
    if (!(std::cin >> value) || value < -1000000000 || value > 1000000000) {
        std::cerr << "Error\n";
        return 1;
    }
    const DoubleOperation operation;
    const Operation& base = operation;
    std::cout << base.apply(value) << '\n';
    return 0;
}
