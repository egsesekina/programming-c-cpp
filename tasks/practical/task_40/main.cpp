#include <iostream>
#include <string>

struct Student {
    std::string name;
    int grade;
};

int main() {
    Student student;
    std::getline(std::cin, student.name);
    std::cin >> student.grade;
    std::cout << "Name: " << student.name << '\n';
    std::cout << "Grade: " << student.grade << '\n';
    return 0;
}
