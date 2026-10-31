/*
 * Задание 46. Реализовать шаблонный стек с const- и non-const-доступом
 * к вершине и исключениями при обращении к пустому стеку.
 * Ввод: число операций, затем push X, pop, top или replace X.
 * Вывод: значение вершины для каждой операции top.
 * Пример: push 10 / push 20 / top -> 20.
 */
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    // Добавляет элемент на вершину.
    void push(const T& value) {
        data.push_back(value);
    }

    // Удаляет верхний элемент.
    void pop() {
        if (data.empty()) throw std::out_of_range("Stack is empty");
        data.pop_back();
    }

    // Возвращает верхний элемент по ссылке.
    T& top() {
        if (data.empty()) throw std::out_of_range("Stack is empty");
        return data.back();
    }

    const T& top() const {
        if (data.empty()) throw std::out_of_range("Stack is empty");
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }
};

int main() {
    int operation_count;
    if (!(std::cin >> operation_count) || operation_count < 1 ||
        operation_count > 100000) {
        std::cerr << "Error\n";
        return 1;
    }

    Stack<int> stack;
    try {
        for (int i = 0; i < operation_count; ++i) {
            std::string command;
            if (!(std::cin >> command)) throw std::invalid_argument("Input");
            if (command == "push") {
                int value;
                if (!(std::cin >> value)) throw std::invalid_argument("Input");
                stack.push(value);
            } else if (command == "pop") {
                stack.pop();
            } else if (command == "top") {
                const Stack<int>& const_stack = stack;
                std::cout << const_stack.top() << '\n';
            } else if (command == "replace") {
                int value;
                if (!(std::cin >> value)) throw std::invalid_argument("Input");
                stack.top() = value;
            } else {
                throw std::invalid_argument("Unknown command");
            }
        }
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}
