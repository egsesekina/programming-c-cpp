/*
 * Задание 50. Реализовать банковский счёт с проверкой операций исключениями.
 * Ввод: начальный баланс, число операций, затем deposit X или withdraw X.
 * Вывод: итоговый баланс.
 * Пример: 1000 / deposit 500 / withdraw 200 -> 1300.00.
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

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
        if (amount > std::numeric_limits<double>::max() - balance)
            throw std::overflow_error("Balance overflow");
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
        double initial_balance;
        int operation_count;
        if (!(std::cin >> initial_balance >> operation_count) ||
            operation_count < 0 || operation_count > 100000)
            throw std::invalid_argument("Input");

        BankAccount account(initial_balance);
        for (int i = 0; i < operation_count; ++i) {
            std::string command;
            double amount;
            if (!(std::cin >> command >> amount))
                throw std::invalid_argument("Input");
            if (command == "deposit") {
                account.deposit(amount);
            } else if (command == "withdraw") {
                account.withdraw(amount);
            } else {
                throw std::invalid_argument("Unknown command");
            }
        }
        std::cout << std::fixed << std::setprecision(2)
                  << account.getBalance() << '\n';
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}
