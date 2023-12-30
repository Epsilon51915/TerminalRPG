#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

#include "inventory.hpp"
#include "enemy.hpp"

using namespace std;
using namespace std::chrono_literals;

class Player
{
    private:
// ------------------------[Stats]-------------------------
    string name_;
    int max_hp_;
    int hp_;
    int atk_;
    int def_;
    int speed_;
    int mgk_atk_;
    int mgk_def_;
    int lvl_;
    int exp_;
    vector<Inventory> player_inventory;
    int player_area_;

    public:
    
    // -----------------------------------[Constructors]--------------------------------------
    Player();

    // -----------------------------------[Setters]-------------------------------------------
    void setName(string);
    void setMaxHP(int);
    void setHP(int);
    void setATK(int);
    void setDEF(int);
    void setSPD(int);
    void setMGKATK(int);
    void setMGKDEF(int);
    void setLVL(int);
    void setEXP(int);
    void setInventory(Inventory);
    void changePlayerArea();

    // -----------------------------------[Getters]-------------------------------------------
    string getName();
    int getHP();
    int getMAX_HP();
    int getATK();
    int getDEF();
    int getSPD();
    int getMGK_ATK();
    int getMGK_DEF();
    int getLVL();
    int getEXP();
    void getStats();
    string getPlayerArea();
    int getPlayerAreaInt();

    // -------------------------------[Other Interfaces]----------------------------------
    void displayInventory();
    bool checkForLevelUp();
    void levelUp();
};


#endif