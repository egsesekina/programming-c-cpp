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
