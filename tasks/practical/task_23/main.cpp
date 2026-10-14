#include <iostream>

int main() {
    int month;
    std::cin >> month;
    switch (month) {
        case 12:
        case 1:
        case 2:
            std::cout << "Winter\n";
            break;
        case 3:
        case 4:
        case 5:
            std::cout << "Spring\n";
            break;
        case 6:
        case 7:
        case 8:
            std::cout << "Summer\n";
            break;
        case 9:
        case 10:
        case 11:
            std::cout << "Autumn\n";
            break;
        default:
            std::cout << "Error\n";
    }
    return 0;
}
