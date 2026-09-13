#include <vector>
#include <string>
using namespace std;

enum class BookingStatus
{
    CONFIRMED,
    CANCELLED,
    FAILED
};

class Booking
{
private:
    string bookingId;
    Customer customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;

public:
    Booking(
        string id,
        const Customer& c,
        Show* s,
        const vector<ShowSeat*>& selected,
        double amount)
        : bookingId(id),
          customer(c),
          show(s),
          seats(selected),
          totalAmount(amount),
          status(BookingStatus::FAILED)
    {
    }

    string getBookingId() const
    {
        return bookingId;
    }

    Customer getCustomer() const
    {
        return customer;
    }

    Show* getShow() const
    {
        return show;
    }

    const vector<ShowSeat*>& getSeats() const
    {
        return seats;
    }

    double getTotalAmount() const
    {
        return totalAmount;
    }

    BookingStatus getStatus() const
    {
        return status;
    }

    void confirm()
    {
        status = BookingStatus::CONFIRMED;
    }

    void cancel()
    {
        status = BookingStatus::CANCELLED;
    }
};