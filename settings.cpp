#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include "settings.hpp"

using namespace std;

int Settings::showGameSettings(){

    int settings_input = -1;
    cout << "Text speed: " << fixed << setprecision(1) << text_speed.count() / 1000 << " seconds." << endl;
    this_thread::sleep_for(text_speed);
    do
    {
    cout << "Press 1 to edit settings. Press 0 to exit." << endl;
    cin >> settings_input;
    if (settings_input != 0 && settings_input != 1)
    {
        cout << "Nope. Try again." << endl;
        this_thread::sleep_for(text_speed);
    }
    } while (settings_input != 1 && settings_input != 0);
    return settings_input;

}

void Settings::changeSettings(int settings_input)
{   
    if (settings_input == 1)
    {
        int text_speed_new;
        cout << "[1. .5s]" << endl;
        cout << "[2. 1s]" << endl;
        cout << "[3. 1.5s]" << endl;
        cout << "[4. 2s]" << endl;
        cout << "[5. 3s]" << endl;
        cin >> text_speed_new;
        this_thread::sleep_for(text_speed);
        switch (text_speed_new)
        {
        case 1:
            text_speed = 500ms;
            break;

        case 2:
            text_speed = 1000ms;
            break;

        case 3:
            text_speed = 1500ms;
            break;

        case 4:
            text_speed = 2000ms;
            break;

        case 5:
            text_speed = 3000ms;
            break;

        default:
            cout << "Man you should really go to a math class. Or kindergarten. That's where you learn numbers." << endl;
            break;
        }
        cout << "Text speed changed." << endl;
        this_thread::sleep_for(text_speed);
        return;
    }
    else{};
    return;
}