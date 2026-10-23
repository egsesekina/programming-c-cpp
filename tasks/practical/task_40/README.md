### Задание 40. Структура Student

**Условие.** Считать и вывести запись Student.

#### Формат входных данных

непустое имя отдельной строкой и оценка от 0 до 100.

#### Формат выходных данных

поля Name и Grade. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Структура объединяет связанные поля одного студента. Проверки перед созданием результата сохраняют непустое имя и допустимый диапазон оценки.

#### Алгоритм

1. считать имя и оценку.
2. проверить непустое имя и диапазон.
3. заполнить структуру.
4. вывести оба поля.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 40. Считать и вывести запись Student.
 * Ввод: непустое имя отдельной строкой и оценка от 0 до 100.
 * Вывод: поля Name и Grade.
 * Пример: Elena / 92 -> Name: Elena / Grade: 92.
 */
#include <iostream>
#include <string>

struct Student {
    std::string name;
    int grade;
};

int main() {
    Student student;
    if (!std::getline(std::cin, student.name) || student.name.empty() ||
        !(std::cin >> student.grade) || student.grade < 0 || student.grade > 100) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << "Name: " << student.name << '\n';
    std::cout << "Grade: " << student.grade << '\n';
    return 0;
}

```

#### Пример работы

Ввод:

```text
Elena
92
```

Вывод:

```text
Name: Elena
Grade: 92
```

#### Граничные случаи

Оценки вне 0..100 и пустое имя отклоняются.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
