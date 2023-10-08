#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "playerChoiceCatalogue.hpp"
using namespace std;

    // Player Choices: 
    // Travel
    // Check Stats
    // Check Items
    // Check Purity Items (IF AT LEAST ONE BOSS HAS BEEN DEFEATED)
    // Monster Catalogue (EXPERIMENTAL)
    // Settings
int menu()
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
        this_thread::sleep_for(1000ms);
        break;

    case 2:
        cout << "Checking stats..." << endl;
        this_thread::sleep_for(1000ms);
        break;

    case 3:
        cout << "Opening inventory..." << endl;
        this_thread::sleep_for(1000ms);
        break;

    case 4:
        cout << "Dusting off the Monster Catalogue..." << endl;
        this_thread::sleep_for(1000ms);
        break;

    case 5:
        cout << "Opening Settings..." << endl;
        this_thread::sleep_for(1000ms);
        break;
    
    default:
        break;
    }
    return player_selection;
}

