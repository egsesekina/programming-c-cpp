#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    bool prime = n >= 2;
    // Проверяем делители, не превосходящие квадратный корень.
    for (long long d = 2; prime && d <= n / d; ++d) {
        if (n % d == 0) prime = false;
    }
    std::cout << (prime ? "Prime" : "Not prime") << '\n';
    return 0;
}
