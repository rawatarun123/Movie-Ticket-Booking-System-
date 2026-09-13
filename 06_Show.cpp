#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Show
{
private:
    int showId;
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(int id, Movie* m, Screen* s, string time)
        : showId(id),
          movie(m),
          screen(s),
          startTime(time)
    {
        for (const auto& seat : s->getSeats())
        {
            showSeats.emplace_back(seat);
        }
    }

    int getShowId() const
    {
        return showId;
    }

    Movie* getMovie() const
    {
        return movie;
    }

    Screen* getScreen() const
    {
        return screen;
    }

    string getStartTime() const
    {
        return startTime;
    }

    void displaySummary() const
    {
        cout << "[" << showId << "] "
             << "Screen-" << screen->getScreenNumber()
             << "\t" << startTime << "\n";
    }

    void displaySeats() const
    {
        cout << "\nSCREEN-" << screen->getScreenNumber()
             << "  " << startTime
             << "  |  " << movie->getTitle() << "\n";

        cout << "SILVER   ";

        for (const auto& ss : showSeats)
        {
            if (ss.getType() == SeatType::SILVER)
            {
                cout << ss.getNumber()
                     << "["
                     << (ss.isAvailable() ? " " : "X")
                     << "] ";
            }
        }

        cout << "\nGOLD     ";

        for (const auto& ss : showSeats)
        {
            if (ss.getType() == SeatType::GOLD)
            {
                cout << ss.getNumber()
                     << "["
                     << (ss.isAvailable() ? " " : "X")
                     << "] ";
            }
        }

        cout << "\nPLATINUM ";

        for (const auto& ss : showSeats)
        {
            if (ss.getType() == SeatType::PLATINUM)
            {
                cout << ss.getNumber()
                     << "["
                     << (ss.isAvailable() ? " " : "X")
                     << "] ";
            }
        }

        cout << "\n([ ] = available, [X] = booked)\n";
    }

    ShowSeat* findSeat(const string& number)
    {
        for (auto& ss : showSeats)
        {
            if (ss.getNumber() == number)
                return &ss;
        }

        return nullptr;
    }
};