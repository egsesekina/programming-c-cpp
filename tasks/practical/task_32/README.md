### Задание 32. Пространства имён и приведения типов

**Условие.** Разместить одноимённые типы Length в разных пространствах имён и показать безопасные явные преобразования `static_cast` и `dynamic_cast`.

#### Формат входных данных

единица измерения `cm` или `ft`, затем неотрицательная длина. Для `cm` вводится целое число до 100000000, для `ft` — конечное вещественное число до 1000000.

#### Формат выходных данных

метры и футы с тремя знаками после точки. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Одинаковое имя `Length` не конфликтует, потому что типы находятся в разных пространствах имён. Вход хранится через полиморфный базовый класс. `dynamic_cast` безопасно определяет фактический производный тип, а `static_cast<double>` явно переводит целое число сантиметров в вещественное значение перед делением.

#### Алгоритм

1. проверить единицу измерения и значение.
2. создать производный объект ввода и хранить его через базовый тип.
3. определить производный тип с помощью `dynamic_cast` и получить метры.
4. преобразовать метры в футы и вывести оба значения.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 32. Разместить одноимённые типы Length в разных пространствах
 * имён и показать static_cast и dynamic_cast при преобразовании длины.
 * Ввод: единица cm или ft и неотрицательная длина.
 * Вывод: метры и футы с тремя знаками после точки.
 * Пример: 100 -> 1.000 m / 3.281 ft.
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

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

class MeasurementInput {
public:
    virtual ~MeasurementInput() = default;
};

class CentimeterInput : public MeasurementInput {
public:
    explicit CentimeterInput(long long value) : centimeters(value) {}
    long long centimeters;
};

class FootInput : public MeasurementInput {
public:
    explicit FootInput(double value) : feet(value) {}
    double feet;
};

metric::Length toMetric(const MeasurementInput& input) {
    if (const auto* centimeters =
            dynamic_cast<const CentimeterInput*>(&input)) {
        return {static_cast<double>(centimeters->centimeters) / 100.0};
    }
    if (const auto* feet = dynamic_cast<const FootInput*>(&input)) {
        return {feet->feet / 3.28083989501312};
    }
    throw std::invalid_argument("Unsupported measurement type");
}

int main() {
    std::string unit;
    std::unique_ptr<MeasurementInput> input;
    if (!(std::cin >> unit)) {
        std::cerr << "Error\n";
        return 1;
    }

    if (unit == "cm") {
        long long centimeters;
        if (!(std::cin >> centimeters) || centimeters < 0 ||
            centimeters > 100000000) {
            std::cerr << "Error\n";
            return 1;
        }
        input = std::make_unique<CentimeterInput>(centimeters);
    } else if (unit == "ft") {
        double feet;
        if (!(std::cin >> feet) || !std::isfinite(feet) ||
            feet < 0.0 || feet > 1000000.0) {
            std::cerr << "Error\n";
            return 1;
        }
        input = std::make_unique<FootInput>(feet);
    } else {
        std::cerr << "Error\n";
        return 1;
    }

    try {
        const metric::Length metric_length = toMetric(*input);
        const imperial::Length imperial_length = toImperial(metric_length);
        std::cout << std::fixed << std::setprecision(3)
                  << metric_length.meters << " m\n"
                  << imperial_length.feet << " ft\n";
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
cm 100
```

Вывод:

```text
1.000 m
3.281 ft
```

#### Граничные случаи

Нулевая длина допустима; неизвестная единица, отрицательное или неконечное значение отклоняются.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
