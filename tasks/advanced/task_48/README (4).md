### Задание 48. Полиморфизм и виртуальные функции

**Вопрос.** Создайте абстрактный класс `Shape` и классы `Rectangle` и `Circle`. Вычислите площади объектов через указатели на базовый класс.

**Правильный ответ:** правильный ответ — приведённая ниже реализация.

**Объяснение:** виртуальная функция обеспечивает динамический полиморфизм, а `unique_ptr` автоматически освобождает память.

**Листинг программы:**

```cpp
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
