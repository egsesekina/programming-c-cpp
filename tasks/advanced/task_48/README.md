### Задание 48. Полиморфизм и виртуальные функции

**Условие.** Вычислить площади фигур через полиморфный интерфейс Shape.

#### Формат входных данных

отсутствует.

#### Формат выходных данных

площади прямоугольника 4x5 и круга радиуса 3. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Абстрактный базовый класс задаёт виртуальный интерфейс площади. Вызов через `unique_ptr<Shape>` выбирает реализацию фактической фигуры, а виртуальный деструктор обеспечивает правильное уничтожение.

#### Алгоритм

1. создать фигуры во владеющих указателях.
2. хранить их через базовый тип.
3. вызвать виртуальную `area`.
4. вывести площади.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 48. Вычислить площади фигур через полиморфный интерфейс Shape.
 * Ввод: отсутствует.
 * Вывод: площади прямоугольника 4x5 и круга радиуса 3.
 * Пример запуска: program -> 20.00 / 28.27.
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (!std::isfinite(w) || !std::isfinite(h) || w <= 0 || h <= 0)
            throw std::invalid_argument("Dimensions must be positive");
    }
    double area() const override { return width * height; }
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {
        if (!std::isfinite(r) || r <= 0)
            throw std::invalid_argument("Radius must be positive");
    }
    double area() const override {
        const double pi = 3.141592653589793;
        return pi * radius * radius;
    }
};

int main() {
    try {
        std::vector<std::unique_ptr<Shape>> shapes;
        shapes.push_back(std::make_unique<Rectangle>(4, 5));
        shapes.push_back(std::make_unique<Circle>(3));

        std::cout << std::fixed << std::setprecision(2);
        for (const auto& shape : shapes) {
            std::cout << shape->area() << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

```

#### Пример работы

Ввод:

```text
не требуется
```

Вывод:

```text
20.00
28.27
```

#### Граничные случаи

Неконечные и неположительные размеры запрещены конструкторами; память освобождается автоматически.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
