### Задание 46. Шаблонный стек

**Условие.** Реализовать шаблонный стек с const- и non-const-доступом к вершине и исключениями при обращении к пустому стеку.

#### Формат входных данных

отсутствует.

#### Формат выходных данных

20 и 10 на отдельных строках. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Вектор хранит элементы и управляет памятью, а методы реализуют порядок LIFO. Перегрузки `top()` сохраняют константность: изменяемый стек возвращает `T&`, константный — `const T&`.

#### Алгоритм

1. поместить два значения в стек.
2. прочитать вершину.
3. удалить вершину.
4. снова прочитать вершину.

#### Исходный код

[main.cpp](main.cpp)

```cpp
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

```

#### Пример работы

Ввод:

```text
не требуется
```

Вывод:

```text
20
10
```

#### Граничные случаи

`pop` и обе версии `top` выбрасывают `std::out_of_range` для пустого стека.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
