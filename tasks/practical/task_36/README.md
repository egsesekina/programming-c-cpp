### Задание 36. Рекурсивное вычисление степени

**Вопрос.** Вычислите `a^n` рекурсивно для целого неотрицательного `n`. Результат должен помещаться в `long long`.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <iostream>

long long power(long long a, unsigned int n) {
    if (n == 0) return 1; // Базовый случай.
    return a * power(a, n - 1);
}

int main() {
    long long a;
    unsigned int n;
    std::cin >> a >> n;
    std::cout << power(a, n) << '\n';
    return 0;
}
```
