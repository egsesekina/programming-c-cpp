### Задание 7. Строки и длина UTF-8

#### Теоретическая часть

**Вопрос.** Какой заголовочный файл объявляет `std::string`? Выберите ответ и объясните свой выбор.

- A) `<cmath>`
- Б) `<string>`
- В) `<fstream>`
- Г) `<cstdlib>`

**Правильный ответ:** Б) `<string>`.

**Эталонное объяснение:** `std::string` объявлен в `<string>`. `<cmath>` содержит математические функции, `<fstream>` — файловые потоки, `<cstdlib>` — общие функции библиотеки C. Подключение `<iostream>` иногда косвенно делает `std::string` доступным в конкретной реализации, но полагаться на транзитивные включения нельзя.

#### Практическая часть

**Условие.** Напишите программу, которая считывает строку UTF-8 и выводит число Unicode-кодовых точек, а не число байтов.

**Формат входных данных:** Одна строка в корректной кодировке UTF-8.

**Формат выходных данных:** Количество кодовых точек. При нарушении формата программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

**Разбор решения:** `std::string::size()` возвращает байты. Программа определяет длину UTF-8-последовательности по старшему байту и проверяет байты продолжения.

**Алгоритм:**

1. считать строку целиком.
2. определить длину очередной UTF-8-последовательности.
3. проверить байты продолжения.
4. увеличить число символов и перейти к следующей последовательности.

**Исходный код:** [main.cpp](main.cpp)

```cpp
/*
 * Задание 7. Подсчитать число Unicode-символов в корректной строке UTF-8.
 * Ввод: одна строка UTF-8.
 * Вывод: количество кодовых точек, а не байтов.
 * Пример: Привет мир -> 10.
 */
#include <iostream>
#include <string>

bool utf8Length(const std::string& text, std::size_t& count) {
    count = 0;
    for (std::size_t i = 0; i < text.size();) {
        const unsigned char lead = static_cast<unsigned char>(text[i]);
        std::size_t length = 0;
        if (lead <= 0x7F) length = 1;
        else if (lead >= 0xC2 && lead <= 0xDF) length = 2;
        else if (lead >= 0xE0 && lead <= 0xEF) length = 3;
        else if (lead >= 0xF0 && lead <= 0xF4) length = 4;
        else return false;

        if (i + length > text.size()) return false;
        for (std::size_t j = 1; j < length; ++j) {
            const unsigned char byte = static_cast<unsigned char>(text[i + j]);
            if ((byte & 0xC0) != 0x80) return false;
        }
        i += length;
        ++count;
    }
    return true;
}

int main() {
    std::string text;
    if (!std::getline(std::cin, text)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::size_t count;
    if (!utf8Length(text, count)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << count << '\n';
    return 0;
}

```

**Пример входных данных:**

```text
Привет мир
```

**Пример выходных данных:**

```text
10
```

**Граничные случаи:** Пустая строка имеет длину 0; некорректная UTF-8-последовательность даёт `Error`.

**Компиляция и запуск:**

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
