#include <vector>
#include <string>
using namespace std;

class Cinema
{
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string n)
        : name(n) {}

    string getName() const
    {
        return name;
    }

    void addScreen(const Screen& screen)
    {
        screens.push_back(screen);
    }

    const vector<Screen>& getScreens() const
    {
        return screens;
    }

    Screen* getScreen(int number)
    {
        for (auto& screen : screens)
        {
            if (screen.getScreenNumber() == number)
                return &screen;
        }

        return nullptr;
    }
};