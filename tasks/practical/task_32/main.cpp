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
