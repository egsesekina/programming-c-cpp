#include <iostream>

// Аргумент передаётся по ссылке.
void increment(int& value) {
    ++value;
}

int main() {
    int number = 10;
    increment(number);
    std::cout << number << '\n'; // 11
    return 0;
}
