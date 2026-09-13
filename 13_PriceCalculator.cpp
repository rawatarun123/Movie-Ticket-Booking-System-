#include <vector>
using namespace std;

class PriceCalculator
{
public:
    double calculate(
        const vector<ShowSeat*>& seats) const
    {
        double total = 0;

        for (const auto* seat : seats)
        {
            if (seat->getType() == SeatType::SILVER)
                total += 150;

            else if (seat->getType() == SeatType::GOLD)
                total += 250;

            else
                total += 400;
        }

        return total;
    }
};