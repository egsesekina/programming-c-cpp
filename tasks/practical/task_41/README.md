### Задание 41. Файловые потоки C++

**Условие.** Считать целые числа из input.txt и записать сумму в output.txt.

#### Формат входных данных

файл input.txt с целыми числами.

#### Формат выходных данных

файл output.txt с суммой; Error в stderr при любой ошибке. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Потоки RAII закрывают файлы автоматически. Чтение продолжается до конца файла, отдельно проверяются посторонние данные и переполнение `long long`.

#### Алгоритм

1. открыть входной файл.
2. суммировать числа с контролем переполнения.
3. проверить достижение конца файла.
4. открыть выходной файл и записать сумму.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 41. Считать целые числа из input.txt и записать сумму в output.txt.
 * Ввод: файл input.txt с целыми числами.
 * Вывод: файл output.txt с суммой; Error в stderr при любой ошибке.
 * Пример: input.txt = "2 3 -1" -> output.txt = "4".
 */
#include <climits>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Error\n";
        return 1;
    }
    long long sum = 0;
    long long x;
    while (input >> x) {
        if ((x > 0 && sum > LLONG_MAX - x) ||
            (x < 0 && sum < LLONG_MIN - x)) {
            std::cerr << "Error\n";
            return 1;
        }
        sum += x;
    }
    if (!input.eof()) {
        std::cerr << "Error\n";
        return 1;
    }
    std::ofstream output("output.txt");
    if (!output) {
        std::cerr << "Error\n";
        return 1;
    }
    output << sum << '\n';
    return 0;
}

```

#### Пример работы

Ввод:

```text
input.txt: 2 3 -1
```

Вывод:

```text
output.txt: 4
```

#### Граничные случаи

Пустой файл даёт 0; нечисловые данные, переполнение и ошибки открытия дают `Error`.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
