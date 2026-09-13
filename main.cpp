#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_ShowSeat.cpp"
#include "06_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_UpiPayment.cpp"
#include "11_CardPayment.cpp"
#include "12_CashPayment.cpp"
#include "13_PriceCalculator.cpp"
#include "14_TicketPrinter.cpp"
#include "15_BookingService.cpp"

int main()
{
    BookingService system;

    system.run();

    return 0;
}