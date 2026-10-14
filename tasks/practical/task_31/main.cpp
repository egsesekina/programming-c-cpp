#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) return 1;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    return 0;
}
