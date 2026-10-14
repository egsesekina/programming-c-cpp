#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 0 || n > 20) {
        std::cout << "Error\n";
        return 1;
    }
    // По определению 0! = 1.
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    std::cout << result << '\n';
    return 0;
}
