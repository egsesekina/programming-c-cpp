/*
 * Задание 46. Реализовать шаблонный стек с const- и non-const-доступом
 * к вершине и исключениями при обращении к пустому стеку.
 * Ввод: отсутствует.
 * Вывод: 20 и 10 на отдельных строках.
 * Пример запуска: program -> 20 / 10.
 */
#include <iostream>
#include <stdexcept>
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
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    std::cout << stack.top() << '\n'; // 20
    stack.pop();
    std::cout << stack.top() << '\n'; // 10
    return 0;
}
