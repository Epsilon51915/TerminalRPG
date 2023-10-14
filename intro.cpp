#include <iostream>
#include <iomanip>

#include "intro.hpp"
#include "sleepFor.hpp"
#include "settings.hpp"
using namespace std;

void intro()
{
    cout << 
    "        |   |                                                         |   |" << endl <<
    "        |   |                                                         |   |" << endl <<
    "        |   |                                                         |   |" << endl <<
    "       /    |                                                         |    \\ " << endl <<
    "       |   /                                                           \\    |" << endl <<
    "       |   |                                                            |   |" << endl <<
    "      /    |                                                            |    \\ " << endl <<
    "      |   /                                                              \\    |" << endl <<  
    "      |   |                                                               |   |" << endl <<
    "      |   |---[]---[]---[]---[]---[]---[]---[]---[]---[]---[]---[]---[]---|   |" << endl <<
    "      |   |                                                               |   |" << endl <<
    "     /    | Terminal RPG - A Terminal - Based RPG. If you can believe it. |   |" << endl <<
    "     |   /                 (Aren't all RPG's terminal?)                   \\   \\" << endl <<
    "     |   |-----------------------------------------------------------------|   |" << endl <<
    "     |   |                                                                 |   |" << endl <<
    "     |   |                                                                 |   |" << endl <<
    "     |   |                                                                 |   |" << endl <<
    "    /    |                                                                 |   |" << endl <<
    "    |   /                                                                   \\   \\ " << endl <<
    "    |   |                                                                   |   |" << endl <<
    "    |   |                                                                   |   |" << endl <<
    "    |   |                                                                   |   |" << endl <<
    "    |   |                                                                   |   |" << endl <<
    "    |   |                                                                   |   |" << endl;

}
int selectScreen(Settings& settings){

    int input;
    
    do
    {
    cout << endl << endl << "Options: " << endl;
    cout << "[1. Start Game]" << "     [2. About]" << endl;
    cout << endl;
    cout << "[3. Patreon(?)]" << "     [4. Close Game]" << endl;
    cout << endl;   
    cin >> input;
    cin.ignore();
    cout << endl;
    switch (input)
        {
        case 1:
            cout << "Beginning game!!" << endl << endl;
            sleepFor(settings.text_speed);
            break;

        case 2:
            cout << "This is a small RPG created by a bored CSCI student" << endl;
            sleepFor(settings.text_speed);
            cout << "spanning X lines of C++ code, this is a tiny passion project" << endl;
            sleepFor(settings.text_speed);
            cout << "that has no purpose besides proving to myself that I can" << endl;
            sleepFor(settings.text_speed);
            cout << "do this. With that being said, enjoy!" << endl;
            sleepFor(settings.text_speed);
            break;

        case 3:
            cout << "My Patreon is" << endl;
            sleepFor(settings.text_speed);
            cout << "up your ass!" << endl;
            sleepFor(settings.text_speed);
            break;

        case 4:
            cout << "Exiting program . . ." << endl;
            sleepFor(settings.text_speed);
            cout << ". . ." << endl;
            sleepFor(settings.text_speed);
            cout << ". . ." << endl;
            sleepFor(settings.text_speed);
            return input;
            break;
        
        default:
            cout << "It seems like you're not good with numbers!" << endl;
            sleepFor(settings.text_speed);
            cout << "Don't worry, a lot of people aren't!" << endl;
            sleepFor(settings.text_speed);
            cout << "So we can try this again." << endl;
            sleepFor(settings.text_speed);
            cout << "You've got this!" << endl;
            sleepFor(settings.text_speed);
            break;
        }
    } while(input !=  1);

    return input;
}