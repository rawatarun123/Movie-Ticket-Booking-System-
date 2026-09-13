#include <string>
using namespace std;

enum class SeatType
{
    SILVER,
    GOLD,
    PLATINUM
};

class Seat
{
private:
    string number;
    SeatType type;

public:
    Seat(string n, SeatType t)
        : number(n), type(t) {}

    string getNumber() const
    {
        return number;
    }

    SeatType getType() const
    {
        return type;
    }

    string typeName() const
    {
        if (type == SeatType::SILVER)
            return "SILVER";

        if (type == SeatType::GOLD)
            return "GOLD";

        return "PLATINUM";
    }
};