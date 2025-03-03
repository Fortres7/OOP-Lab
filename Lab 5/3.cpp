#include <iostream>
using namespace std;

class ValidateString
{
private:
    string Str;

public:
    ValidateString(const string &str) : Str(str) {}

    bool isValid() const
    {
        for (char c : Str)
        {
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string S1, S2;

    cout << "Enter first string: ";
    cin >> S1;
    cout << "Enter second string: ";
    cin >> S2;

    ValidateString obj1(S1);
    ValidateString obj2(S2);

    if (obj1.isValid())
    {
        cout << "First string is valid" << endl;
    }
    else
    {
        cout << "First string is invalid" << endl;
    }

    if (obj2.isValid())
    {
        cout << "Second string is valid" << endl;
    }
    else
    {
        cout << "Second string is invalid" << endl;
    }

    return 0;
}
