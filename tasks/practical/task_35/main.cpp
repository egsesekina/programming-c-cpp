#include <iostream>

// Алгоритм Евклида.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    if (a < 0 || b < 0) return 1;
    std::cout << gcd(a, b) << '\n';
    return 0;
}
