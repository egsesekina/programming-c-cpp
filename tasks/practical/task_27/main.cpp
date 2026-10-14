#include <algorithm>
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::max({a, b, c}) << '\n';
    return 0;
}
