### Задание 40. Структура данных

**Вопрос.** Создайте структуру `Student` с именем и оценкой; считайте и выведите сведения об одном студенте.

**Правильный ответ:** программа должна выводить результат, соответствующий условию задачи.

**Листинг программы:**

```cpp
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
```
