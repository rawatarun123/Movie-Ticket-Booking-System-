#include <iostream>
using namespace std;

class UpiPayment : public Payment
{
public:
    bool pay(double amount) override
    {
        cout << "[UPI] Rs."
             << amount
             << " paid successfully\n";

        return true;
    }
};