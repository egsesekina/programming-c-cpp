### Задание 37. Строки и подсчёт символов

**Вопрос.** Подсчитайте количество букв `а` и `А` в строке.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int count = 0;
    for (char c : s) {
        if (c == 'a' || c == 'A') ++count;
    }
    std::cout << count << '\n';
    return 0;
}
```
