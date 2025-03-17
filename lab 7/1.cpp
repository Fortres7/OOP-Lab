#include<iostream>
using namespace std;


class Amount{
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

    public:

    void deposit(double amount){
        balance = balance + amount;
    }

    void withdraw(double amount){

        if (amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficent Fund!" << endl;
        }        
    }

    void getAccountInfo(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type" << accountType << endl;
    }


};

class SavingsAccount : public Amount{

    float interestRate;
    double minimumBalance;

    public:

};

class CheckingAccount : public Amount{
    

};

class FixedDepositAccount : public Amount{
    
    int maturityDate;
    float fixedInterestRate;

    public:
            
};



int main(){






    return 0;
}
