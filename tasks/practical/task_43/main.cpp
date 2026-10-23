/*
 * Задание 43. Создать прямоугольник только из конечных положительных сторон.
 * Ввод: длина и ширина типа double.
 * Вывод: площадь либо Error для <= 0, NaN, infinity или неверного ввода.
 * Пример: 3 4 -> 12.
 */
#include <cmath>
#include <iostream>
#include <stdexcept>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        if (!std::isfinite(l) || !std::isfinite(w) || l <= 0 || w <= 0) {
            throw std::invalid_argument("Dimensions must be positive");
        }
    }

    double area() const { return length * width; }
};

int main() {
    try {
        double l, w;
        if (!(std::cin >> l >> w)) {
            std::cerr << "Error\n";
            return 1;
        }
        Rectangle rectangle(l, w);
        std::cout << rectangle.area() << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}
