#include <iostream>

long long power(long long a, unsigned long long n) {
    if (n == 0) return 1; // Базовый случай.

    // Возведение в степень делением показателя пополам сохраняет
    // рекурсивное решение, но требует только O(log n) вызовов.
    const long long half = power(a, n / 2);
    return n % 2 == 0 ? half * half : half * half * a;
}

int main() {
    long long a, n;
    if (!(std::cin >> a >> n) || n < 0) {
        std::cout << "Error\n";
        return 1;
    }
    std::cout << power(a, static_cast<unsigned long long>(n)) << '\n';
    return 0;
}
