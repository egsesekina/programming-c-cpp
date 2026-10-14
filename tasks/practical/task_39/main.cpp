#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 100) return 1;
    long long diagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            std::cin >> x;
            if (i == j) diagonalSum += x;
        }
    }
    std::cout << diagonalSum << '\n';
    return 0;
}
