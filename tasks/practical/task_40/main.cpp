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
