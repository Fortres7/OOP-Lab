#include <iostream>
using namespace std;
class LoanHelper
{
private:
    static const float interestRate;
    float amount;
    int months;

public:
    LoanHelper(float a, int m)
    {
        amount = a;
        months = m;
    }
    void loanRepayment()
    {
        float x, y;
        x = amount / months;
        y = x + x * interestRate;
        cout << "You have to pay " << y << " for every " << months << " month" << endl;
    }
};
const float LoanHelper::interestRate = (0.5 / 100);

int main()
{
    LoanHelper l1(1500, 5);
    l1.loanRepayment();
    LoanHelper l2(500, 2);
    l2.loanRepayment();

    return 0;
}
