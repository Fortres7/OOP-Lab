#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() {
        balance = 0.0;
    }

    Account(string accNum, string holderName, double bal = 0.0) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << "\n";
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << "\n";
    }
};

int main() {
    Account acc1("10", "Maarij", 500.0);
    Account acc2("20", "Saad");

    acc1.checkBalance();
    acc2.checkBalance();

    acc1.deposit(200.0);
    acc1.checkBalance();

    acc1.withdraw(100.0);
    acc1.checkBalance();

    acc2.deposit(150.0);
    acc2.checkBalance();

    acc2.withdraw(200.0);
    acc2.checkBalance();

    return 0;
}
