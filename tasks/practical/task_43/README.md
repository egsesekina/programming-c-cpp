### Задание 43. Конструктор и методы класса

**Вопрос.** Создайте класс `Rectangle`, вычисляющий площадь; размеры должны быть положительными.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <iostream>
#include <stdexcept>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        if (l <= 0 || w <= 0) {
            throw std::invalid_argument("Dimensions must be positive");
        }
    }

    double area() const { return length * width; }
};

int main() {
    try {
        double l, w;
        std::cin >> l >> w;
        Rectangle rectangle(l, w);
        std::cout << rectangle.area() << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
```
