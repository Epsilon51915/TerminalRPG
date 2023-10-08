#include <iostream>
#include <chrono>
#include <thread>

#include "intro.hpp"
#include "player.hpp"
#include "playerChoiceCatalogue.hpp"
using namespace std;

string promptAndGetName()
{
    cout << "What is your name? ";
    string name;
    getline(cin, name);
    cout << endl;
    return name;
}

void menuChoice(int, Inventory user);

int main(){
    intro();

    this_thread::sleep_for(1000ms);

    int input = selectScreen();
    if (input == 4)
    {
        return 0;
    }
    string name = promptAndGetName();
    Player user(name);
    Inventory user1;
    user.sayHello();
    this_thread::sleep_for(1500ms);
    user.getLore();
    this_thread::sleep_for(2000ms);

    int player_selection = 0;
    while (player_selection != 1)
    {
    player_selection = menu();
        menuChoice(player_selection);
    }
    return 0;
}

void menuChoice(int player_selection, Player& user)
{
    switch (player_selection)
    {
    case 1:
        // Call getTravel()
        break;

    case 2:
        user.getStats();
        this_thread::sleep_for(3000ms);
        break;

    case 3:
        // user.getInventory();
        // Because this doesn't work anyways
        break;

    case 4:
        // Call getMonsterCatalogue()
        break;

    case 5:
        // Call gameSettings()
        break;
    
    default:
        cout << "Hey buddy, what'd we say about numbers?" << endl;
        break;
    }
}