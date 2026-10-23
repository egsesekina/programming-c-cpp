### Задание 32. Пространства имён и приведения типов

**Условие.** Разместить одноимённые типы Length в разных пространствах имён и выполнить явное безопасное преобразование через static_cast.

#### Формат входных данных

длина в целых сантиметрах от 0 до 100000000.

#### Формат выходных данных

метры и футы с тремя знаками после точки. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Одинаковое имя `Length` не конфликтует, потому что типы находятся в разных пространствах имён. `static_cast<double>` явно переводит целое число сантиметров в вещественное значение перед делением.

#### Алгоритм

1. проверить сантиметры.
2. явно преобразовать число в `double` и получить метры.
3. вызвать функцию преобразования.
4. вывести оба значения.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 32. Разместить одноимённые типы Length в разных пространствах
 * имён и выполнить явное безопасное преобразование через static_cast.
 * Ввод: длина в целых сантиметрах от 0 до 100000000.
 * Вывод: метры и футы с тремя знаками после точки.
 * Пример: 100 -> 1.000 m / 3.281 ft.
 */
#include <iomanip>
#include <iostream>

namespace metric {
struct Length {
    double meters;
};
}

namespace imperial {
struct Length {
    double feet;
};
}

imperial::Length toImperial(metric::Length value) {
    return {value.meters * 3.28083989501312};
}

int main() {
    long long centimeters;
    if (!(std::cin >> centimeters) || centimeters < 0 ||
        centimeters > 100000000) {
        std::cerr << "Error\n";
        return 1;
    }

    const metric::Length metric_length{
        static_cast<double>(centimeters) / 100.0
    };
    const imperial::Length imperial_length = toImperial(metric_length);
    std::cout << std::fixed << std::setprecision(3)
              << metric_length.meters << " m\n"
              << imperial_length.feet << " ft\n";
    return 0;
}

```

#### Пример работы

Ввод:

```text
100
```

Вывод:

```text
1.000 m
3.281 ft
```

#### Граничные случаи

Нулевая длина допустима; верхняя граница сохраняет точность результата для учебного примера.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
