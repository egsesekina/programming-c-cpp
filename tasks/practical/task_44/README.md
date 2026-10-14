### Задание 44. Перегрузка функций

**Вопрос.** Реализуйте `maxValue` для двух и для трёх целых чисел.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <algorithm>
#include <iostream>

int maxValue(int a, int b) {
    return a > b ? a : b;
}

int maxValue(int a, int b, int c) {
    return std::max(maxValue(a, b), c);
}

int main() {
    std::cout << maxValue(4, 7) << '\n';
    std::cout << maxValue(4, 7, 2) << '\n';
    return 0;
}
```
