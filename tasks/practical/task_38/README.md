### Задание 38. Проверка палиндрома

**Вопрос.** Определите, является ли строка палиндромом с учётом регистра и пробелов.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    std::cout << (s == reversed ? "Yes" : "No") << '\n';
    return 0;
}
```
