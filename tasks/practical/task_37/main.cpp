#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int count = 0;
    for (char c : s) {
        if (c == 'a' || c == 'A') ++count;
    }
    std::cout << count << '\n';
    return 0;
}
