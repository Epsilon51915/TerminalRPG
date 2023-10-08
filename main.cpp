#include <iostream>
#include <chrono>
#include <thread>

#include "intro.hpp"
#include "player.hpp"
#include "playerChoiceCatalogue.hpp"
#include "settings.hpp"
#include "sleepFor.hpp"
using namespace std;

string promptAndGetName()
{
    cout << "What is your name? ";
    string name;
    getline(cin, name);
    cout << endl;
    return name;
}

void menuChoice(int, Player& user, Settings& settings, int);



int main(){

    Settings settings;
    intro();

    this_thread::sleep_for(settings.text_speed);

    int input = selectScreen();
    if (input == 4)
    {
        return 0;
    }
    string name = promptAndGetName();
    Player user(name);
    if (name == "")
    {
        user.level = 1000;
        user.health = 1000;
        user.attack = 1000;
        user.defense = 1000;
        user.speed = 1000;
        user.magic_attack = 1000;
        user.magic_defense = 1000;
        user.exp = 1000;
    }
    user.sayHello();
    this_thread::sleep_for(1500ms); // settings.text_speed + 500ms to modify
    user.printLore();
    this_thread::sleep_for(2000ms);

    int player_selection = 0;
    while (player_selection != 1)
    {
    player_selection = menu();
        menuChoice(player_selection, user, settings, input);
    }
    return 0;
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
        this_thread::sleep_for(3000ms);
        break;

    case 3:
        user.inventory.printInventory();
        cout << endl;
        this_thread::sleep_for(3000ms);
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
        this_thread::sleep_for(settings.text_speed + 2000ms);
        break;
    
    default:
        cout << "Hey buddy, what'd we say about numbers?" << endl;
        break;
    }
}