#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <string>

#include "item.hpp"
#include "enemy.hpp"

class Player
{
    private:
// ------------------------[Stats]-------------------------
    std::string name_;
    int max_hp_;
    int hp_;
    int atk_;
    int def_;
    int speed_;
    int mgk_atk_;
    int mgk_def_;
    int lvl_;
    int exp_;
    Item player_inventory[10];
    int player_area_;

    public:
    
    // -----------------------------------[Constructors]--------------------------------------
    Player();

    // -----------------------------------[Setters]-------------------------------------------
    void setName(std::string);
    void setMaxHP(int);
    void setHP(int);
    void setATK(int);
    void setDEF(int);
    void setSPD(int);
    void setMGKATK(int);
    void setMGKDEF(int);
    void setLVL(int);
    void setEXP(int);
    void setInventory();
    void changePlayerArea();

    // -----------------------------------[Getters]-------------------------------------------
    std::string getName();
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
    std::string getPlayerArea();
    int getPlayerAreaInt();

    // -------------------------------[Other Interfaces]----------------------------------
    void displayInventory();
    bool checkForLevelUp();
    void levelUp();
};


#endif