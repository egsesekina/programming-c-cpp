### Задание 46. Реализация стека с использованием шаблона

**Вопрос.** Реализуйте шаблонный стек с операциями `push`, `pop`, `top` и `empty`. При обращении к пустому стеку выбрасывайте исключение.

**Правильный ответ:** правильный ответ — приведённая ниже реализация.

**Объяснение:** стек работает по принципу LIFO. Вектор управляет памятью автоматически.

**Листинг программы:**

```cpp
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
