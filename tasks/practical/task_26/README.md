### Задание 26. Факториал

**Вопрос.** Вычислите `N!` для `N` от 0 до 20; при недопустимом вводе выведите `Error`.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 0 || n > 20) {
        std::cout << "Error\n";
        return 1;
    }
    // По определению 0! = 1.
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    std::cout << result << '\n';
    return 0;
}
```
