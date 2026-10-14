#include <algorithm>
#include <iostream>

int maxValue(int a, int b) {
    return a > b ? a : b;
}

int maxValue(int a, int b, int c) {
    return std::max(maxValue(a, b), c);
}

int main() {
    std::cout << maxValue(4, 7) << '\n';
    std::cout << maxValue(4, 7, 2) << '\n';
    return 0;
}
