#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <memory>
#include <iomanip>

using namespace std;

class BookingService
{
private:
    Cinema cinema;

    vector<Movie> movies;
    vector<Show> shows;
    vector<Booking> bookings;

    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;

    int nextBookingNumber = 1001;

    void seedData()
    {
        movies.emplace_back(
            "3 Idiots", "Hindi", 170);

        movies.emplace_back(
            "Interstellar", "English", 169);

        Screen screen1(1);

        screen1.addSeat(
            Seat("A1", SeatType::SILVER));
        screen1.addSeat(
            Seat("A2", SeatType::SILVER));
        screen1.addSeat(
            Seat("A3", SeatType::SILVER));
        screen1.addSeat(
            Seat("A4", SeatType::SILVER));

        screen1.addSeat(
            Seat("B1", SeatType::GOLD));
        screen1.addSeat(
            Seat("B2", SeatType::GOLD));
        screen1.addSeat(
            Seat("B3", SeatType::GOLD));
        screen1.addSeat(
            Seat("B4", SeatType::GOLD));

        screen1.addSeat(
            Seat("C1", SeatType::PLATINUM));
        screen1.addSeat(
            Seat("C2", SeatType::PLATINUM));

        cinema.addScreen(screen1);

        Screen screen2(2);

        screen2.addSeat(
            Seat("A1", SeatType::SILVER));
        screen2.addSeat(
            Seat("A2", SeatType::SILVER));
        screen2.addSeat(
            Seat("A3", SeatType::SILVER));
        screen2.addSeat(
            Seat("A4", SeatType::SILVER));

        screen2.addSeat(
            Seat("B1", SeatType::GOLD));
        screen2.addSeat(
            Seat("B2", SeatType::GOLD));
        screen2.addSeat(
            Seat("B3", SeatType::GOLD));
        screen2.addSeat(
            Seat("B4", SeatType::GOLD));

        screen2.addSeat(
            Seat("C1", SeatType::PLATINUM));
        screen2.addSeat(
            Seat("C2", SeatType::PLATINUM));

        cinema.addScreen(screen2);

        shows.emplace_back(
            1,
            &movies[0],
            cinema.getScreen(1),
            "06:00 PM");

        shows.emplace_back(
            2,
            &movies[0],
            cinema.getScreen(2),
            "09:00 PM");

        shows.emplace_back(
            3,
            &movies[1],
            cinema.getScreen(1),
            "07:00 PM");

        shows.emplace_back(
            4,
            &movies[1],
            cinema.getScreen(2),
            "10:00 PM");
    }

    void listMovies() const
    {
        cout << "\nMovies currently playing:\n";

        for (size_t i = 0;
             i < movies.size();
             i++)
        {
            cout << "[" << i + 1 << "] ";

            movies[i].display();
        }
    }

    vector<Show*> getShowsForMovie(
        int movieIndex)
    {
        vector<Show*> result;

        for (auto& show : shows)
        {
            if (show.getMovie()
                == &movies[movieIndex])
            {
                result.push_back(&show);
            }
        }

        return result;
    }

    int readInt(
        const string& prompt,
        int min,
        int max) const
    {
        int value;

        while (true)
        {
            cout << prompt;

            if (cin >> value &&
                value >= min &&
                value <= max)
            {
                cin.ignore(10000, '\n');

                return value;
            }

            cout << "Invalid input. "
                 << "Enter a value from "
                 << min << " to "
                 << max << ".\n";

            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    string readNonEmpty(
        const string& prompt) const
    {
        string value;

        do
        {
            cout << prompt;
            getline(cin, value);

            if (value.empty())
            {
                cout << "Input cannot be empty.\n";
            }

        } while (value.empty());

        return value;
    }

    vector<string> readSeatNumbers() const
    {
        cout << "Seats (e.g. A1,A2): ";

        string line;
        getline(cin, line);

        for (char& c : line)
        {
            if (c == ',')
                c = ' ';
        }

        string token;

        stringstream ss(line);

        vector<string> result;

        set<string> uniqueSeats;

        while (ss >> token)
        {
            if (uniqueSeats.insert(token).second)
            {
                result.push_back(token);
            }
        }

        return result;
    }

    Booking* findBooking(
        const string& id)
    {
        for (auto& booking : bookings)
        {
            if (booking.getBookingId() == id)
            {
                return &booking;
            }
        }

        return nullptr;
    }

    unique_ptr<Payment> choosePayment(
        int choice)
    {
        if (choice == 1)
            return make_unique<UpiPayment>();

        if (choice == 2)
            return make_unique<CardPayment>();

        return make_unique<CashPayment>();
    }

    void bookTicket()
    {
        listMovies();

        int movieChoice =
            readInt(
                "Choose movie: ",
                1,
                (int)movies.size());

        vector<Show*> movieShows =
            getShowsForMovie(
                movieChoice - 1);

        cout << "\nShows:\n";

        for (Show* show : movieShows)
        {
            show->displaySummary();
        }

        int showChoice =
            readInt(
                "Choose show: ",
                1,
                (int)movieShows.size());

        Show* show =
            movieShows[showChoice - 1];

        show->displaySeats();

        vector<string> seatNumbers =
            readSeatNumbers();

        if (seatNumbers.empty())
        {
            cout << "No seats selected. "
                 << "Booking cancelled.\n";

            return;
        }

        vector<ShowSeat*> selectedSeats;

        for (const string& number :
             seatNumbers)
        {
            ShowSeat* seat =
                show->findSeat(number);

            if (!seat)
            {
                cout << "Seat "
                     << number
                     << " does not exist.\n";

                return;
            }

            if (!seat->isAvailable())
            {
                cout << "Seat "
                     << number
                     << " is already booked.\n";

                return;
            }

            selectedSeats.push_back(seat);
        }

        string name =
            readNonEmpty(
                "Customer name: ");

        string phone =
            readNonEmpty(
                "Phone: ");

        double total =
            priceCalculator.calculate(
                selectedSeats);

        cout << "TOTAL       Rs."
             << fixed
             << setprecision(0)
             << total
             << "\n";

        cout << "Pay by: "
             << "1.UPI  2.Card  3.Cash\n";

        int paymentChoice =
            readInt(
                "Choose payment: ",
                1,
                3);

        Customer customer(
            name,
            phone);

        stringstream id;

        id << "BK"
           << nextBookingNumber++;

        Booking booking(
            id.str(),
            customer,
            show,
            selectedSeats,
            total);

        unique_ptr<Payment> payment =
            choosePayment(
                paymentChoice);

        if (!payment->pay(total))
        {
            cout << "Payment failed. "
                 << "Booking NOT confirmed.\n";

            return;
        }

        for (ShowSeat* seat :
             selectedSeats)
        {
            seat->book();
        }

        booking.confirm();

        bookings.push_back(booking);

        cout << "Booking confirmed successfully.\n";

        ticketPrinter.print(
            bookings.back());
    }

    void cancelBooking()
    {
        string id =
            readNonEmpty(
                "Enter booking ID: ");

        Booking* booking =
            findBooking(id);

        if (!booking)
        {
            cout << "Booking not found.\n";
            return;
        }

        if (booking->getStatus()
            != BookingStatus::CONFIRMED)
        {
            cout << "Only a confirmed booking "
                 << "can be cancelled.\n";

            return;
        }

        for (ShowSeat* seat :
             booking->getSeats())
        {
            seat->makeAvailable();
        }

        booking->cancel();

        cout << "Booking "
             << id
             << " cancelled. "
             << "Seats are AVAILABLE again.\n";
    }

    void showMyTickets() const
    {
        bool found = false;

        cout << "\nYour bookings:\n";

        for (const auto& booking :
             bookings)
        {
            found = true;

            cout << booking.getBookingId()
                 << " | "
                 << booking.getShow()
                        ->getMovie()
                        ->getTitle()
                 << " | Status: ";

            if (booking.getStatus()
                == BookingStatus::CONFIRMED)
            {
                cout << "CONFIRMED";
            }
            else
            {
                cout << "CANCELLED";
            }

            cout << "\n";
        }

        if (!found)
        {
            cout << "No bookings yet.\n";
        }
    }

public:

    BookingService()
        : cinema("PVR Demo Cinema")
    {
        seedData();
    }

    void run()
    {
        while (true)
        {
            cout << "\n";
            cout << "===== MOVIE TICKET BOOKING =====\n";

            cout << "1. Movies  "
                 << "2. Book  "
                 << "3. Cancel  "
                 << "4. My tickets  "
                 << "0. Exit\n";

            int choice =
                readInt(
                    "Choose: ",
                    0,
                    4);

            switch (choice)
            {
                case 1:
                    listMovies();
                    break;

                case 2:
                    bookTicket();
                    break;

                case 3:
                    cancelBooking();
                    break;

                case 4:
                    showMyTickets();
                    break;

                case 0:
                    cout << "Thank you!\n";
                    return;
            }
        }
    }
};