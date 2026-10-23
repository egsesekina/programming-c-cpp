### Задание 31. Множественное наследование

**Условие.** Создать класс Document с множественным наследованием от интерфейсов Identifiable и Printable.

#### Формат входных данных

положительный идентификатор, затем название отдельной строкой.

#### Формат выходных данных

идентификатор и название через интерфейсы базовых классов. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Два базовых класса задают независимые интерфейсы. `Document` реализует оба, поэтому один объект можно использовать через ссылки `Identifiable` и `Printable`; виртуальные деструкторы делают интерфейсы безопасными для полиморфного использования.

#### Алгоритм

1. считать идентификатор и название.
2. создать `Document`.
3. получить ссылки на оба базовых интерфейса.
4. вызвать методы через эти ссылки.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 31. Создать класс Document с множественным наследованием от
 * интерфейсов Identifiable и Printable.
 * Ввод: положительный идентификатор, затем название отдельной строкой.
 * Вывод: идентификатор и название через интерфейсы базовых классов.
 * Пример: 17 / Practice report -> ID: 17 / Title: Practice report.
 */
#include <iostream>
#include <limits>
#include <string>
#include <utility>

class Identifiable {
public:
    virtual int id() const = 0;
    virtual ~Identifiable() = default;
};

class Printable {
public:
    virtual void print(std::ostream& output) const = 0;
    virtual ~Printable() = default;
};

class Document final : public Identifiable, public Printable {
private:
    int id_;
    std::string title_;

public:
    Document(int id, std::string title) : id_(id), title_(std::move(title)) {}
    int id() const override { return id_; }
    void print(std::ostream& output) const override {
        output << "Title: " << title_ << '\n';
    }
};

int main() {
    int id;
    if (!(std::cin >> id) || id <= 0) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string title;
    if (!std::getline(std::cin, title) || title.empty()) {
        std::cerr << "Error\n";
        return 1;
    }

    const Document document(id, title);
    const Identifiable& identified = document;
    const Printable& printable = document;
    std::cout << "ID: " << identified.id() << '\n';
    printable.print(std::cout);
    return 0;
}

```

#### Пример работы

Ввод:

```text
17
Practice report
```

Вывод:

```text
ID: 17
Title: Practice report
```

#### Граничные случаи

Пустое название и неположительный идентификатор отклоняются.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
