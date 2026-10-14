#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }
    long long sum = 0;
    int x;
    while (input >> x) sum += x;
    if (!input.eof()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }
    std::ofstream output("output.txt");
    if (!output) {
        std::cerr << "Cannot open output.txt\n";
        return 1;
    }
    output << sum << '\n';
    return 0;
}
