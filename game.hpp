#ifndef GAME_HPP
#define GAME_HPP

#include <chrono>
#include <thread>
#include <iomanip>
#include <fstream>
#include <vector>

#include "enemy.hpp"
#include "player.hpp"
#include "inventory.hpp"

using namespace std;
using namespace std::chrono_literals;

class Game
{
    private:
    Player player_;
    Enemy enemy_;
    int encounters_;
    int battle_exp_;
    // bool game_over = false;
    // bool player_dead = false;
    vector<Enemy> all_enemies_;
    chrono::duration <double, milli> text_speed_ = 2000ms;

    public:
    //----------------------[Constructor]----------------------------------
    Game();

    //----------------------[Setters]-------------------------------------
    void setPlayer(Player);

    //----------------------[Sleep For + Related Functions]---------------
    chrono::duration <double, milli> getTextSpeed();
    void sleepFor();

    //----------------------[Intro Functions]-----------------------------
    void displayIntro();
    void displayLore();
    string promptAndGetName();
    int selectScreen();
    bool getAllEnemies();
    void setSeed(int);
    int getRandomNumber();

    //----------------------[Game Functions]------------------------------
    bool menu();
    int displayMonsterCatalogueMenu();
    void displayMonsterCataloguePage(int);
    bool travel();
    void deathGameOver();
        //------------------------[Combat Functions]---------------------------
        void getPlainsEnemy();
        void getForestEnemy();
        void getMountainEnemy();
        void getCastleEnemy();

        void randomiseEnemyStats();
        
        bool combat();
        void enemyTurn();
        bool playerTurn();
        bool runAway();

    //------------------------------[Settings]----------------------------
    int showSettings();
    void changeSettings(int);
};

#endif