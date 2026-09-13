#include <string>
using namespace std;

class Customer
{
private:
    string name;
    string phone;

public:
    Customer(string n, string p)
        : name(n), phone(p) {}

    string getName() const
    {
        return name;
    }

    string getPhone() const
    {
        return phone;
    }
};