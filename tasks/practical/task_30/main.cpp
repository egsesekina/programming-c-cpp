#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) return 1;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    auto bounds = std::minmax_element(a.begin(), a.end());
    std::cout << *bounds.first << ' ' << *bounds.second << '\n';
    return 0;
}
