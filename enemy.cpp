#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "enemy.hpp"

using namespace std;

//-------------------------------[Getters]--------------------------------
string Enemy::getEnemyName()
{
    return enemy_name_;
}

int Enemy::getEnemyHP()
{
    return enemy_hp_;
}

int Enemy::getEnemyATK()
{
    return enemy_atk_;
}

int Enemy::getEnemyDEF()
{
    return enemy_def_;
}

int Enemy::getEnemySPD()
{
    return enemy_spd_;
}

int Enemy::getEnemyMGKATK()
{
    return enemy_mgk_atk_;
}

int Enemy::getEnemyMGKDEF()
{
    return enemy_mgk_def_;
}

int Enemy::getEnemyLVL()
{
    return enemy_lvl_;
}

string Enemy::getEnemyDescription()
{
    return enemy_description_;
}

//----------------------------------[Setters]---------------------------------------------------
void Enemy::setEnemyName(string name)
{
    enemy_name_ = name;
}

void Enemy::setEnemyHP(int hp)
{
    enemy_hp_ = hp;
}

void Enemy::setEnemyATK(int atk)
{
    enemy_atk_ = atk;
}

void Enemy::setEnemyDEF(int def)
{
    enemy_def_ = def;
}

void Enemy::setEnemySPD(int spd)
{
    enemy_spd_ = spd;
}

void Enemy::setEnemyMGKATK(int mgk_atk)
{
    enemy_mgk_atk_ = mgk_atk;
}

void Enemy::setEnemyMGKDEF(int mgk_def)
{
    enemy_mgk_def_ = mgk_def;
}

void Enemy::setEnemyLVL(int lvl)
{
    enemy_lvl_ = lvl;
}

void Enemy::setEnemyID(int id)
{
    enemy_id_ = id;
}

void Enemy::setEnemyDescription(string description)
{
    enemy_description_ = description;
}