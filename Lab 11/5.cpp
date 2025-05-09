#include <iostream>
using namespace std;
class InsufficientFundsException : public exception {
    double deficit;
public:
    InsufficientFundsException(double d) : deficit(d) {}

    const char* what() const noexcept override {
        return "InsufficientFundsException";
    }

    double getDeficit() const {
        return deficit;
    }
};
template <typename T>
class BankAccount {
    T balance;
public:
    BankAccount(T initialBalance) : balance(initialBalance) {}
    void withdraw(T amount) {
        if (amount > balance) {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
    }
    void displayBalance() const {
        cout << "Balance: $" << balance << endl;
    }
};
int main() {
    BankAccount<double> account(500.00);
    account.displayBalance();
    try {
        account.withdraw(600.00); 
    } catch (const InsufficientFundsException& e) {
        cout << "Withdraw $600: " << e.what() << " - Deficit: $" << e.getDeficit() << endl;
    }

    return 0;
}
