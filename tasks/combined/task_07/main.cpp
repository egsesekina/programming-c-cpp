#include <iostream>
#include <string>

int main() {
    std::string text;
    // Считываем всю строку, включая пробелы.
    std::getline(std::cin, text);
    std::cout << text.size() << '\n';
    return 0;
}
