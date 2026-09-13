#include <iostream>
#include <string>
using namespace std;

class Movie
{
private:
    string title;
    string language;
    int duration;

public:
    Movie(string t, string l, int d)
        : title(t), language(l), duration(d) {}

    string getTitle() const
    {
        return title;
    }

    string getLanguage() const
    {
        return language;
    }

    int getDuration() const
    {
        return duration;
    }

    void display() const
    {
        cout << title << "\t"
             << language << "\t"
             << duration << " min\n";
    }
};