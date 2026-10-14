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

    // Русские буквы кодируются двумя байтами в UTF-8.
    const std::string lowercaseA = "\xD0\xB0"; // а
    const std::string uppercaseA = "\xD0\x90"; // А
    int count = 0;
    for (std::size_t i = 0; i < s.size();) {
        if (s.compare(i, lowercaseA.size(), lowercaseA) == 0 ||
            s.compare(i, uppercaseA.size(), uppercaseA) == 0) {
            ++count;
            i += lowercaseA.size();
        } else {
            ++i;
        }
    }
    std::cout << count << '\n';
    return 0;
}
```
