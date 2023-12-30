#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <vector>

using namespace std;

class Enemy
{
    private:
    //Name,HP,ATK,DEF,SPD,MGK_ATK,MGK_DEF,LVL;
    string enemy_name_;
    int enemy_hp_;
    int enemy_atk_;
    int enemy_def_;
    int enemy_spd_;
    int enemy_mgk_atk_;
    int enemy_mgk_def_;
    int enemy_lvl_;
    int enemy_id_;
    string enemy_description_;

    public:
    //-------------------[Getters]-------------------
    string getEnemyName();
    int getEnemyHP();
    int getEnemyATK();
    int getEnemyDEF();
    int getEnemySPD();
    int getEnemyMGKATK();
    int getEnemyMGKDEF();
    int getEnemyLVL();
    string getEnemyDescription();

    //--------------------[Setters]-------------------
    void setEnemyName(string);
    void setEnemyHP(int);
    void setEnemyATK(int);
    void setEnemyDEF(int);
    void setEnemySPD(int);
    void setEnemyMGKATK(int);
    void setEnemyMGKDEF(int);
    void setEnemyLVL(int);
    void setEnemyID(int);
    void setEnemyDescription(string);
};

#endif