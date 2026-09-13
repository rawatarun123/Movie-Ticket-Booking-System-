#include <vector>
using namespace std;

class Screen
{
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int n)
        : screenNumber(n) {}

    int getScreenNumber() const
    {
        return screenNumber;
    }

    void addSeat(const Seat& seat)
    {
        seats.push_back(seat);
    }

    const vector<Seat>& getSeats() const
    {
        return seats;
    }
};