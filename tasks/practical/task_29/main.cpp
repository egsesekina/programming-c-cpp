#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) return 1;
    std::vector<int> a(n);
    long long sum = 0;
    for (int& x : a) {
        std::cin >> x;
        sum += x;
    }
    std::cout << sum << '\n';
    return 0;
}
