#include <iostream>
#include <string>
#include "playerChoiceCatalogue.hpp"
#include "sleepFor.hpp"
#include "settings.hpp"
#include "player.hpp"
using namespace std;

    // Player Choices: 
    // Travel
    // Check Stats
    // Check Items
    // Check Purity Items (IF AT LEAST ONE BOSS HAS BEEN DEFEATED)
    // Monster Catalogue (EXPERIMENTAL)
    // Settings
int menu(Settings& settings)
{
    cout << "[1. Travel]            [2. Check Stats]" <<  endl;
    cout << "[3. Check Items]       {4. Monster Catalogue}" << endl;
    cout << "[5. Settings]" << endl;
    cout << "Select an Option: ";
    int player_selection;
    cin >> player_selection;
    cout << endl;
    switch (player_selection)
    {
    case 1:
        cout << "Beginning travels..." << endl;
        sleepFor(settings.text_speed);
        break;

    case 2:
        cout << "Checking stats..." << endl;
        sleepFor(settings.text_speed);
        break;

    case 3:
        cout << "Opening inventory..." << endl;
        sleepFor(settings.text_speed);
        break;

    case 4:
        cout << "Dusting off the Monster Catalogue..." << endl;
        sleepFor(settings.text_speed);
        break;

    case 5:
        cout << "Opening Settings..." << endl;
        sleepFor(settings.text_speed);
        break;
    
    default:
        break;
    }
    return player_selection;
}

void menuChoice(int player_selection, Player& user, Settings& settings, int input)
{
    switch (player_selection)
    {
    case 1:
        // Call printTravel()
        break;

    case 2:
        user.printStats();
        sleepFor(settings.text_speed);
        break;

    case 3:
        user.inventory.printInventory();
        cout << endl;
        sleepFor(settings.text_speed);
        break;
        // user.inventory.item1.quantity++;
    case 4:
        // Call printMonsterCatalogue()
        break;

    case 5:
        input = 0;
        input = settings.showGameSettings(input);
        if (input != 0)
        {
            settings.changeSettings(input);
        }
        cout << endl;
        sleepFor(settings.text_speed);
        break;
    
    default:
        cout << "Hey buddy, what'd we say about numbers?" << endl;
        break;
    }
}

