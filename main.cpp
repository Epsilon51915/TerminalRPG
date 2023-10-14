#include <iostream>

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

int main(){

    Settings settings;

    // Plays intro
    intro();

    sleepFor(settings.text_speed);

    // Shows the user the start screen
    int input = selectScreen();

    // User quit the game.
    if (input == 4)
    {
        return 0;
    }

    // Get player name
    string name = promptAndGetName();
    Player user(name);

    // Dev mode
    if (name == "Epsilon")
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

    // Say hello to user
    user.sayHello();
    sleepFor(settings.text_speed); // settings.text_speed + 500ms to modify

    // Game lore that I totally didn't just write up in 30 seconds.
    user.printLore();
    sleepFor(settings.text_speed);

    
    int player_selection = 0;
    

    while (player_selection != 1)
    {
    // Show the user the out of battle menu, allow the user to make a choice
    player_selection = menu(settings);

    // Based on the user's choice, display different screens.
    menuChoice(player_selection, user, settings, input);
    }

    return 0;
}

