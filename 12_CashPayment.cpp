#include <iostream>
using namespace std;

class CashPayment : public Payment
{
public:
    bool pay(double amount) override
    {
        cout << "[CASH] Rs."
             << amount
             << " received successfully\n";

        return true;
    }
};