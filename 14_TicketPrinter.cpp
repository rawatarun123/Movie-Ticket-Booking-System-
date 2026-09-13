#include <iostream>
#include <iomanip>
using namespace std;

class TicketPrinter
{
public:
    void print(const Booking& booking) const
    {
        cout << "\n";
        cout << "================ TICKET ================\n";

        cout << "Booking ID : "
             << booking.getBookingId() << "\n";

        cout << "Customer   : "
             << booking.getCustomer().getName() << "\n";

        cout << "Movie      : "
             << booking.getShow()
                    ->getMovie()
                    ->getTitle()
             << "\n";

        cout << "Screen     : Screen-"
             << booking.getShow()
                    ->getScreen()
                    ->getScreenNumber()
             << "\n";

        cout << "Time       : "
             << booking.getShow()
                    ->getStartTime()
             << "\n";

        cout << "Seats      : ";

        for (size_t i = 0;
             i < booking.getSeats().size();
             i++)
        {
            if (i > 0)
                cout << ", ";

            cout << booking.getSeats()[i]
                    ->getNumber();
        }

        cout << "\n";

        cout << "Amount     : Rs."
             << fixed << setprecision(0)
             << booking.getTotalAmount()
             << "\n";

        cout << "Status     : CONFIRMED\n";

        cout << "=========================================\n";
    }
};