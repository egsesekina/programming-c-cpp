### Задание 38. Палиндром в UTF-8

**Условие.** Проверить палиндром по Unicode-символам, сохраняя регистр и пробелы. Строка должна быть корректно закодирована в UTF-8.

#### Формат входных данных

одна строка UTF-8.

#### Формат выходных данных

Yes для палиндрома, иначе No; Error для неверного UTF-8. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Строка разбивается на целые последовательности UTF-8, после чего сравниваются симметричные символы. Побайтовый `reverse` не используется, поэтому байты внутри русских букв не меняются местами.

#### Алгоритм

1. считать строку.
2. выделить каждую последовательность UTF-8.
3. сравнить пары от краёв к центру.
4. вывести `Yes` или `No`.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 38. Проверить палиндром по Unicode-символам, сохраняя регистр
 * и пробелы. Строка должна быть корректно закодирована в UTF-8.
 * Ввод: одна строка UTF-8.
 * Вывод: Yes для палиндрома, иначе No; Error для неверного UTF-8.
 * Пример: шалаш -> Yes; аб -> No.
 */
#include <iostream>
#include <string>
#include <vector>

bool splitUtf8(const std::string& text, std::vector<std::string>& characters) {
    for (std::size_t index = 0; index < text.size();) {
        const unsigned char lead = static_cast<unsigned char>(text[index]);
        std::size_t length;
        if (lead <= 0x7F) length = 1;
        else if (lead >= 0xC2 && lead <= 0xDF) length = 2;
        else if (lead >= 0xE0 && lead <= 0xEF) length = 3;
        else if (lead >= 0xF0 && lead <= 0xF4) length = 4;
        else return false;

        if (index + length > text.size()) return false;
        for (std::size_t offset = 1; offset < length; ++offset) {
            const unsigned char byte =
                static_cast<unsigned char>(text[index + offset]);
            if ((byte & 0xC0) != 0x80) return false;
        }
        characters.push_back(text.substr(index, length));
        index += length;
    }
    return true;
}

int main() {
    std::string text;
    if (!std::getline(std::cin, text)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::vector<std::string> characters;
    if (!splitUtf8(text, characters)) {
        std::cerr << "Error\n";
        return 1;
    }
    bool palindrome = true;
    for (std::size_t left = 0, right = characters.size(); left < right; ++left) {
        --right;
        if (characters[left] != characters[right]) {
            palindrome = false;
            break;
        }
    }
    std::cout << (palindrome ? "Yes" : "No") << '\n';
    return 0;
}

```

#### Пример работы

Ввод:

```text
шалаш
```

Вывод:

```text
Yes
```

#### Граничные случаи

Пустая строка и строка из одного символа являются палиндромами; регистр и пробелы учитываются.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
