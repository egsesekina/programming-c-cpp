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
