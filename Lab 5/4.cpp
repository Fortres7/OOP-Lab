#include <iostream>
using namespace std;

class BankAccount
{

private:
  int accountNumber;
  string accountHolderName;
  double balance;

public:
  BankAccount()
  {
  }

  BankAccount(int accountNumber, string accountHolderName, double balance)
  {
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;
  }

  void setValues(int accountNumber, string accountHolderName, double balance)
  {
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;
  }

  void deposit(double amount)
  {
    balance = balance + amount;
  }

  void withdraw(double amount)
  {
    if (amount > balance)
    {
      cout << "Insufficent Balance" << endl;
    }
    else
      balance = balance - amount;
  }

  void display()
  {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Balance: " << balance << endl;
  }
};

int main()
{

  int n;

  cout << "Enter number of Bank Accounts: ";
  cin >> n;
  BankAccount B[n];

  for (int i = 0; i < n; i++)
  {
    int x;
    string y;
    double z;

    cout << "\nEnter details for Account #" << i + 1 << endl;

    cout << "Enter Account Number: ";
    cin >> x;

    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, y);

    cout << "Enter Balance: ";
    cin >> z;

    B[i].setValues(x, y, z);
  }

  cout << "\nDisplaying Details\n";
  for (int i = 0; i < n; i++)
  {
    cout << "\nAccount #" << i + 1 << endl;
    B[i].display();
  }

  cout << "\nUpdated\n";
  B[0].deposit(500);
  B[0].withdraw(200);
  B[0].display();

  return 0;
}
