#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include "player.hpp"

using namespace std;
using namespace std::chrono_literals;


// ---------------------------------[Constructor]-----------------------------------
Player::Player()
{
    name_ = " ";
    hp_ = 10;
    max_hp_ = 10;
    atk_ = 5;
    def_ = 5;
    speed_ = 3;
    mgk_atk_ = 0;
    mgk_def_ = 0;
    lvl_ = 1;
    exp_ = 0;
    player_area_ = 1;
}

//----------------------------------[Setters]---------------------------------------
void Player::setName(string name)
{
    name_ = name;
    if(name_ == "Epsilon")
    {
        max_hp_ = 1000;
        hp_ = 1000;
        atk_ = 1000;
        def_ = 1000;
        speed_ = 1000;
        mgk_atk_ = 1000;
        mgk_def_ = 1000;
        lvl_ = 1000;
        exp_ = 1000;
    }
}

void Player::setInventory(Inventory inventory)
{
    player_inventory = inventory.createInventory();
}

void Player::setMaxHP(int max_hp)
{
    max_hp_ = max_hp;  
}

void Player::setHP(int hp)
{
    hp_ = hp;
}

void Player::setATK(int atk)
{
    atk_ = atk;
}

void Player::setDEF(int def)
{
    def_ = def;
}

void Player::setSPD(int speed)
{
    speed_ = speed;
}

void Player::setMGKATK(int mgkatk)
{
    mgk_atk_ = mgkatk;
}

void Player::setMGKDEF(int mgk_def)
{
    mgk_def_ = mgk_def;
}

void Player::setLVL(int lvl)
{
    lvl_ = lvl;
}

void Player::setEXP(int exp)
{
    exp_ = exp;
}

void Player::changePlayerArea()
{
    player_area_++;
}

// ---------------------------------[Master Getter]---------------------------------
void Player::getStats()
{
    cout << getName() << "'s HP: " <<  getHP() << "/" << getMAX_HP() << endl;
    cout << getName() << "'s ATK: " << getATK() << endl;
    cout << getName() << "'s DEF: " << getDEF() << endl;
    cout << getName() << "'s SPD: " << getSPD() << endl;
    cout << getName() << "'s MGK_ATK: " << getMGK_ATK() << endl;
    cout << getName() << "'s MGK_DEF: " << getMGK_DEF() << endl;
    cout << getName() << "'s LVL: " << getLVL() << endl;
    cout << getName() << "'s EXP: " << getEXP() << endl;
    cout << getName() << "'s Area: " << getPlayerArea() << endl << endl;
}

// ---------------------------------[Getters]---------------------------------------
string Player::getName()
{
    return name_;
}

int Player::getHP()
{
    return hp_;
}

int Player::getMAX_HP()
{
    return max_hp_;
}

int Player::getATK()
{
    return atk_;
}

int Player::getDEF()
{
    return def_;
}

int Player::getSPD()
{
    return speed_;
}

int Player::getMGK_ATK()
{
    return mgk_atk_;
}

int Player::getMGK_DEF()
{
    return mgk_def_;
}

int Player::getLVL()
{
    return lvl_;
}

int Player::getEXP()
{
    return exp_;
}

string Player::getPlayerArea()
{
    switch(player_area_)
    {
        case 1:
            return "Plains";
            break;

        case 2:
            return "Forest";
            break;

        case 3:
            return "Mountains";
            break;

        case 4:
            return "Castle";
            break;
    }
    return " ";
}

int Player::getPlayerAreaInt()
{
    return player_area_;
}

// ---------------------------------[Interfaces]-----------------------------------------------
void Player::displayInventory()
{
    int size = player_inventory.size();
    for(auto i = 0; i < size; i++)
    {
        cout << "[ " << player_inventory[i].getItemName() << " (" << player_inventory[i].getItemQuantity() << "/10) ]" << endl;
    }
    cout << endl;
}

bool Player::checkForLevelUp()
{
    // exp = 100 + 50(L - 1)^(L/7)
    int exp_to_level_up = 100 + ( 50 * pow( (lvl_ - 1), (lvl_ / 6.0) ) );
    if(exp_ > exp_to_level_up)
    {
        return true;
    }
    return false;
}

void Player::levelUp()
{
    int exp_to_level_up = 100 + ( 50 * pow( (lvl_ - 1), (lvl_ / 6) ) );
    int increment;
    int level_up_selection;
    lvl_++;
    setEXP(getEXP() - exp_to_level_up);
    for(int i = 0; i < 6; i++)
    {
        increment = rand() % 4;
        switch(i)
        {
            case 0:
                max_hp_ += increment;
                break;

            case 1:
                atk_ += increment;
                break;

            case 2: 
                def_ += increment;
                break;
            
            case 3:
                speed_ += increment;
                break;

            case 4:
                mgk_atk_ += increment;
                break;

            case 5:
                mgk_def_ += increment;
                break;
        }
    }
    cout << "You have leveled up!!" << endl;
    for(int i = 3; i > 0; i--)
    {
        cout << "Max HP: " << max_hp_ << " + 2  ->  " << max_hp_ + 2 << endl;
        cout << "Attack: " << atk_ << " + 2  ->  " << atk_ + 2 << endl;
        cout << "Defense: " << def_ << " + 2  ->  " << def_ + 2 << endl;
        cout << "Speed: " << speed_ << " + 2  ->  " << speed_ + 2 << endl;
        cout << "Magic Attack: " << mgk_atk_ << " + 2  ->  " << mgk_atk_ + 2 << endl;
        cout << "Magic Defense: " << mgk_def_ << " + 2  ->  " << mgk_def_ + 2 << endl << endl;
        do
        {
        cout << "You have " << i << " level up point(s) left to spend." << endl;
        cout << "Select a stat you would like to spend 1 level up point on!" << endl;
        cin >> level_up_selection;
        if(level_up_selection < 1 || level_up_selection > 6)
        {
            cout << "Maybe I'll just take away points from you instead." << endl << endl;
            cin.clear();
            cin.ignore();
            level_up_selection = 0;
        }
        else
        {
            switch(level_up_selection)
            {
                case 1:
                    max_hp_ += 2;
                    break;

                case 2:
                    atk_ += 2;
                    break;

                case 3:
                    def_ += 2;
                    break;

                case 4:
                    speed_ += 2;
                    break;

                case 5:
                    mgk_atk_ += 2;
                    break;

                case 6:
                    mgk_def_ += 2;
                    break;
            }
        }
        } while(level_up_selection < 1 || level_up_selection > 6);
    }
    setHP(max_hp_); // Heal player
}
