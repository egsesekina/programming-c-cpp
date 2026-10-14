### Задание 32. Сортировка массива

**Вопрос.** Отсортируйте массив целых чисел по возрастанию.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) return 1;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    for (int x : a) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
```
