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
