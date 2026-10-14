### Задание 42. Класс и инкапсуляция

**Вопрос.** Создайте класс `Counter` с операциями увеличения значения и получения текущего значения.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
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
```
