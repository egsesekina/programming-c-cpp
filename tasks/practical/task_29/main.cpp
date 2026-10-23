/*
 * Задание 29. Реализовать класс Student со статическим счётчиком живых
 * объектов и статическим методом liveCount.
 * Ввод: N (0..1000), затем N имён без пробелов.
 * Вывод: число объектов во время жизни контейнера и после его очистки.
 * Пример: 3 / Ann Bob Eva -> 3 / 0.
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Student {
private:
    std::string name_;
    inline static int live_count_ = 0;

public:
    explicit Student(std::string name) : name_(std::move(name)) {
        ++live_count_;
    }
    Student(const Student&) = delete;
    Student& operator=(const Student&) = delete;
    Student(Student&& other) noexcept : name_(std::move(other.name_)) {
        ++live_count_;
    }
    Student& operator=(Student&&) = delete;
    ~Student() { --live_count_; }

    static int liveCount() { return live_count_; }
};

int main() {
    int n;
    if (!(std::cin >> n) || n < 0 || n > 1000) {
        std::cerr << "Error\n";
        return 1;
    }

    std::vector<Student> students;
    students.reserve(static_cast<std::size_t>(n));
    for (int i = 0; i < n; ++i) {
        std::string name;
        if (!(std::cin >> name)) {
            std::cerr << "Error\n";
            return 1;
        }
        students.emplace_back(std::move(name));
    }
    std::cout << Student::liveCount() << '\n';
    students.clear();
    std::cout << Student::liveCount() << '\n';
    return 0;
}
