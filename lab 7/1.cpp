#include<iostream>
using namespace std;

class Amount{
    protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

    public:
    Amount(int accNum, double bal, string holder, string type) {
        accountNumber = accNum;
        balance = bal;
        accountHolderName = holder;
        accountType = type;
    }

    void deposit(double amount){
        balance += amount;
    }

    void withdraw(double amount){
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient Funds!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation not defined for this account type." << endl;
    }

    virtual void printStatement() {
        cout << "Transaction history not available." << endl;
    }

    void getAccountInfo(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
    }
};

class SavingsAccount : public Amount{
    float interestRate;
    double minimumBalance;
    public:
    SavingsAccount(int accNum, double bal, string holder, float rate, double minBal) : Amount(accNum, bal, holder, "Savings") {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        cout << "Interest Earned: " << interest << endl;
    }
};

class CheckingAccount : public Amount{
    public:
    CheckingAccount(int accNum, double bal, string holder) : Amount(accNum, bal, holder, "Checking") {}
};

class FixedDepositAccount : public Amount{
    int maturityDate;
    float fixedInterestRate;
    public:
    FixedDepositAccount(int accNum, double bal, string holder, int matDate, float rate) : Amount(accNum, bal, holder, "Fixed Deposit") {
        maturityDate = matDate;
        fixedInterestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest Earned: " << interest << endl;
    }
};

int main(){
    SavingsAccount savings(101, 5000, "John Doe", 3.5, 1000);
    CheckingAccount checking(102, 2000, "Jane Smith");
    FixedDepositAccount fixed(103, 10000, "Alice Brown", 20251231, 5.0);
    
    savings.getAccountInfo();
    savings.calculateInterest();
    
    checking.getAccountInfo();
    checking.deposit(500);
    checking.withdraw(1000);
    
    fixed.getAccountInfo();
    fixed.calculateInterest();
    
    return 0;
}

