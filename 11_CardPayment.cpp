#include <iostream>
using namespace std;

class CardPayment : public Payment
{
public:
    bool pay(double amount) override
    {
        cout << "[CARD] Rs."
             << amount
             << " paid successfully\n";

        return true;
    }
};