#include <iostream>

class Counter {
private:
    int value;

public:
    explicit Counter(int initial = 0) : value(initial) {}

    void increment() { ++value; }
    int getValue() const { return value; }
};

int main() {
    Counter counter;
    counter.increment();
    counter.increment();
    std::cout << counter.getValue() << '\n';
    return 0;
}
