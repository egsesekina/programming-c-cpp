#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) return 1;
    int count = 0;
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        if (x % 2 == 0) ++count;
    }
    std::cout << count << '\n';
    return 0;
}
