#include <iostream>

template <typename T>
T maxValue(const T& a, const T& b) {
    // Тип T должен поддерживать операцию сравнения.
    return (a < b) ? b : a;
}

int main() {
    std::cout << maxValue(3, 8) << '\n';
    std::cout << maxValue(2.5, 1.7) << '\n';
    return 0;
}
