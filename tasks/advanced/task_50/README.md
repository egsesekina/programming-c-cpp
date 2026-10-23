### Задание 50. Банковский счёт и исключения

**Условие.** Реализовать банковский счёт с проверкой операций исключениями.

#### Формат входных данных

отсутствует.

#### Формат выходных данных

баланс после пополнения на 500 и снятия 200, то есть 1300.00. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Класс хранит баланс закрыто и проверяет каждую операцию внутри метода. Исключения отделяют нормальный сценарий от нарушений инварианта; конечность чисел проверяется через `std::isfinite`.

#### Алгоритм

1. создать счёт с начальным балансом.
2. выполнить пополнение.
3. выполнить снятие.
4. вывести баланс или обработать исключение.

#### Исходный код

[main.cpp](main.cpp)

```cpp
/*
 * Задание 50. Реализовать банковский счёт с проверкой операций исключениями.
 * Ввод: отсутствует.
 * Вывод: баланс после пополнения на 500 и снятия 200, то есть 1300.00.
 * Пример запуска: program -> 1300.00.
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance = 0.0)
        : balance(initialBalance) {
        if (!std::isfinite(initialBalance) || initialBalance < 0.0)
            throw std::invalid_argument("Initial balance must be finite and non-negative");
    }

    void deposit(double amount) {
        if (!std::isfinite(amount) || amount < 0.0)
            throw std::invalid_argument("Deposit must be finite and non-negative");
        balance += amount;
    }

    void withdraw(double amount) {
        if (!std::isfinite(amount) || amount <= 0.0)
            throw std::invalid_argument("Withdrawal must be finite and positive");
        if (amount > balance)
            throw std::runtime_error("Insufficient funds");
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    try {
        BankAccount account(1000.0);
        account.deposit(500.0);
        account.withdraw(200.0);
        std::cout << std::fixed << std::setprecision(2)
                  << account.getBalance() << '\n'; // 1300.00
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

```

#### Пример работы

Ввод:

```text
не требуется
```

Вывод:

```text
1300.00
```

#### Граничные случаи

Нулевое пополнение разрешено, отрицательное запрещено; снятие должно быть положительным и не превышать баланс.

#### Компиляция и запуск

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o program
./program
```
