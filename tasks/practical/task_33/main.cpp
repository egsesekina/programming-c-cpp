#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) return 1;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    int target;
    std::cin >> target;
    auto it = std::find(a.begin(), a.end(), target);
    std::cout << (it == a.end() ? -1 : int(it - a.begin())) << '\n';
    return 0;
}
