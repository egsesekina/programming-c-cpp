### Задание 36. Рекурсивное вычисление степени

**Условие.** Рекурсивно вычислить a^n с контролем переполнения long long.

#### Формат входных данных

целые a и n, где n >= 0.

#### Формат выходных данных

значение степени либо Error при неверном вводе или переполнении. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Быстрое возведение в степень делит показатель пополам и требует `O(log n)` рекурсивных вызовов. Каждое умножение предварительно проверяется делением относительно границ `long long`, поэтому знаковое переполнение не возникает.

#### Алгоритм

1. проверить неотрицательность показателя.
2. рекурсивно вычислить половинную степень.
3. проверить квадрат на переполнение.
4. для нечётного показателя безопасно умножить ещё на основание.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 36. Рекурсивно вычислить a^n с контролем переполнения long long.
 * Ввод: целые a и n, где n >= 0.
 * Вывод: значение степени либо Error при неверном вводе или переполнении.
 * Пример: 3 5 -> 243; 3 40 -> Error.
 */
#include <climits>
#include <iostream>

bool checkedMultiply(long long left, long long right, long long& result) {
    if (left == 0 || right == 0) {
        result = 0;
        return true;
    }
    if (left == -1 && right == LLONG_MIN) return false;
    if (right == -1 && left == LLONG_MIN) return false;

    if (left > 0) {
        if (right > 0 && left > LLONG_MAX / right) return false;
        if (right < 0 && right < LLONG_MIN / left) return false;
    } else {
        if (right > 0 && left < LLONG_MIN / right) return false;
        if (right < 0 && left < LLONG_MAX / right) return false;
    }
    result = left * right;
    return true;
}

bool power(long long base, unsigned long long exponent, long long& result) {
    if (exponent == 0) {
        result = 1;
        return true;
    }
    long long half;
    if (!power(base, exponent / 2, half)) return false;

    long long square;
    if (!checkedMultiply(half, half, square)) return false;
    if (exponent % 2 == 0) {
        result = square;
        return true;
    }
    return checkedMultiply(square, base, result);
}

int main() {
    long long a, n;
    if (!(std::cin >> a >> n) || n < 0) {
        std::cerr << "Error\n";
        return 1;
    }
    long long result;
    if (!power(a, static_cast<unsigned long long>(n), result)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << result << '\n';
    return 0;
}

```

#### Пример работы

Ввод:

```text
3 5
```

Вывод:

```text
243
```

#### Граничные случаи

По определению `a^0 = 1`, включая `0^0` в рамках программы; любое переполнение даёт `Error`.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
