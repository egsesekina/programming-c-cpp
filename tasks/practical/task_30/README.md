### Задание 30. Перегрузка операторов

**Условие.** Реализовать класс Fraction и перегрузить операторы + и <<.

#### Формат входных данных

числитель и ненулевой знаменатель каждой из двух дробей.

#### Формат выходных данных

сокращённая сумма с положительным знаменателем. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Дробь поддерживает инварианты: знаменатель ненулевой и положительный, числитель и знаменатель сокращены. Дружественные операторы получают доступ к закрытым полям и возвращают нормализованный результат.

#### Алгоритм

1. проверить входные границы и знаменатели.
2. создать две нормализованные дроби.
3. сложить их перегруженным оператором.
4. вывести результат оператором `<<`.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 30. Реализовать класс Fraction и перегрузить операторы + и <<.
 * Ввод: числитель и ненулевой знаменатель каждой из двух дробей.
 * Вывод: сокращённая сумма с положительным знаменателем.
 * Пример: 1 6 1 3 -> 1/2.
 */
#include <iostream>
#include <numeric>
#include <stdexcept>

class Fraction {
private:
    long long numerator_;
    long long denominator_;

    void normalize() {
        if (denominator_ == 0) throw std::invalid_argument("zero denominator");
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const long long divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

public:
    Fraction(long long numerator, long long denominator)
        : numerator_(numerator), denominator_(denominator) {
        normalize();
    }

    friend Fraction operator+(const Fraction& left, const Fraction& right) {
        return Fraction(left.numerator_ * right.denominator_ +
                            right.numerator_ * left.denominator_,
                        left.denominator_ * right.denominator_);
    }

    friend std::ostream& operator<<(std::ostream& output, const Fraction& value) {
        return output << value.numerator_ << '/' << value.denominator_;
    }
};

int main() {
    long long a, b, c, d;
    if (!(std::cin >> a >> b >> c >> d) || b == 0 || d == 0 ||
        a < -1000000 || a > 1000000 || b < -1000000 || b > 1000000 ||
        c < -1000000 || c > 1000000 || d < -1000000 || d > 1000000) {
        std::cerr << "Error\n";
        return 1;
    }
    try {
        std::cout << Fraction(a, b) + Fraction(c, d) << '\n';
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}

```

#### Пример работы

Ввод:

```text
1 6 1 3
```

Вывод:

```text
1/2
```

#### Граничные случаи

Нулевой числитель сокращается до `0/1`; отрицательный знак переносится в числитель; знаменатель 0 отклоняется.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
