### Задание 43. Конструктор и инвариант класса

**Условие.** Создать прямоугольник только из конечных положительных сторон.

#### Формат входных данных

длина и ширина типа double.

#### Формат выходных данных

площадь либо Error для <= 0, NaN, infinity или неверного ввода. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Конструктор проверяет инвариант до завершения создания объекта. `std::isfinite` отклоняет не только отрицательные размеры и ноль, но также `NaN` и бесконечность.

#### Алгоритм

1. считать размеры.
2. проверить их в конструкторе.
3. создать объект при корректных данных.
4. вывести площадь или обработать исключение.

#### Исходный код

[main.cpp](main.cpp)

```cpp
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

```

#### Пример работы

Ввод:

```text
3 4
```

Вывод:

```text
12
```

#### Граничные случаи

Ноль, отрицательные числа, `NaN` и бесконечность отклоняются одинаково.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
