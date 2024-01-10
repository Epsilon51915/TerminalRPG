#ifndef GAME_HPP
#define GAME_HPP

#include <chrono>
#include <thread>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <regex>
#include <iterator>

#include "enemy.hpp"
#include "player.hpp"
#include "inventory.hpp"

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
    std::vector<Enemy> all_enemies_;
#if defined(_DEBUG) or defined(DEBUG)
    std::chrono::duration <double, std::milli> text_speed_ = 0ms;
#else
    std::chrono::duration <double, std::milli> text_speed_ = 2000ms;
#endif // DEBUG

    public:
    //----------------------[Constructor]----------------------------------
    Game();

    //----------------------[Setters]-------------------------------------
    void setPlayer(Player);

    Player getPlayer();

    //----------------------[Sleep For + Related Functions]---------------
    std::chrono::duration <double, std::milli> getTextSpeed();
    void sleepFor();

    //----------------------[Intro Functions]-----------------------------
    void displayIntro();
    void displayLore();
    std::string promptAndGetName();
    int selectScreen();
    bool getAllEnemies();
    void setSeed(int);
    int getRandomNumber();

    //----------------------[Game Functions]------------------------------
    bool menu();
    std::string processString(const std::string&);
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