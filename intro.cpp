#include <iostream>
#include <iomanip>

#include "intro.hpp"
#include "sleepFor.hpp"
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
int selectScreen(){

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
            sleepFor(1000ms);
            break;

        case 2:
            cout << "This is a small RPG created by a bored CSCI student" << endl;
            sleepFor(1000ms);
            cout << "spanning X lines of C++ code, this is a tiny passion project" << endl;
            sleepFor(1000ms);
            cout << "that has no purpose besides proving to myself that I can" << endl;
            sleepFor(1000ms);
            cout << "do this. With that being said, enjoy!" << endl;
            sleepFor(1000ms);
            break;

        case 3:
            cout << "My Patreon is" << endl;
            sleepFor(750ms);
            cout << "up your ass!" << endl;
            sleepFor(1000ms);
            break;

        case 4:
            cout << "Exiting program . . ." << endl;
            sleepFor(500ms);
            cout << ". . ." << endl;
            sleepFor(500ms);
            cout << ". . ." << endl;
            sleepFor(500ms);
            return input;
            break;
        
        default:
            cout << "It seems like you're not good with numbers!" << endl;
            sleepFor(1000ms);
            cout << "Don't worry, a lot of people aren't!" << endl;
            sleepFor(1000ms);
            cout << "So we can try this again." << endl;
            sleepFor(1000ms);
            cout << "You've got this!" << endl;
            sleepFor(1000ms);
            break;
        }
    } while(input !=  1);

    return input;
}