#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << "Even\n";
    } else {
        std::cout << "Odd\n";
    }
    return 0;
}
