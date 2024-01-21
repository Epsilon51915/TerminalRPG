#include <iostream>
#include <vector>
#include <chrono>

#include "game.hpp"
#include "colors.hpp"

using namespace std;
using namespace std::chrono;

void run() {
    cout << RESET;
  high_resolution_clock::time_point previous = high_resolution_clock::now();
  Inventory temp;
  Game game;
  if (!game.getAllEnemies())
  {
    cout << "Someone can't program a game right. Or maybe it's just user error." << endl;
    return;
  }
  Player user;
  game.displayIntro();

  // Ends the game if the player chose to.
  if (game.selectScreen() == 4)
  {
    return;
  }

  user.setName(game.promptAndGetName());
  user.setInventory(temp);
  game.setPlayer(user);
  game.sleepFor();
  game.displayLore();

  high_resolution_clock::time_point lap = high_resolution_clock::now();
  duration<double, micro> seed_clock = lap - previous;
  game.setSeed(seed_clock.count());

  do
  {
  } while(game.menu() && game.getPlayer().getPlayerAreaInt() < 5);
}

int main()
{
  run();
  cout << "Press Enter to close!" << endl;
  string dummy;
  getline(cin, dummy);
}