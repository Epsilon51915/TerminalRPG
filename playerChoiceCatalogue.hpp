#ifndef PLAYERCHOICECATALOGUE_HPP
#define PLAYERCHOICECATALOGUE_HPP
struct Player;
struct Settings;
int menu(Settings& settings);
void menuChoice(int, Player& user, Settings& settings, int);
#endif