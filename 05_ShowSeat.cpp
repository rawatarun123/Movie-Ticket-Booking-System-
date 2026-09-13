#include <string>
using namespace std;

enum class SeatStatus
{
    AVAILABLE,
    BOOKED
};

class ShowSeat
{
private:
    Seat seat;
    SeatStatus status;

public:
    ShowSeat(const Seat& s)
        : seat(s), status(SeatStatus::AVAILABLE) {}

    string getNumber() const
    {
        return seat.getNumber();
    }

    SeatType getType() const
    {
        return seat.getType();
    }

    string typeName() const
    {
        return seat.typeName();
    }

    bool isAvailable() const
    {
        return status == SeatStatus::AVAILABLE;
    }

    void book()
    {
        status = SeatStatus::BOOKED;
    }

    void makeAvailable()
    {
        status = SeatStatus::AVAILABLE;
    }
};