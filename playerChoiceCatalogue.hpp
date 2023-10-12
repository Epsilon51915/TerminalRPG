#ifndef PLAYERCHOICECATALOGUE_HPP
#define PLAYERCHOICECATALOGUE_HPP
#include "settings.hpp"
#include "player.hpp"
int menu(Settings& settings);
void menuChoice(int, Player& user, Settings& settings, int);
#endif