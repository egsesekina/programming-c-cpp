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
