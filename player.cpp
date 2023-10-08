#include <iostream>
#include <chrono>
#include <thread>
// this_thread::sleep_for(1000ms);

#include "player.hpp"
using namespace std;



Player::Player(const std::string& name) : name(name), level(1), health(5), attack(1), defense(0), speed(5), magic_attack(0), magic_defense(0), exp(0) {}


void Player::sayHello()
{
    cout << "Hello " << name << "!" << endl << endl;
    return;
}

void Player::getLore()
{
    cout << "Yeah there's a king in a castle doing shady stuff probably." << endl;
    this_thread::sleep_for(1000ms);
    cout << "Probably planning on raising taxes again." << endl;
    this_thread::sleep_for(1000ms);
    cout << "Or hosting a badmitton tournament." << endl;
    this_thread::sleep_for(1000ms);
    cout << "You should stop him. Maybe. I don't care." << endl << endl;
    this_thread::sleep_for(1000ms);
}

void Player::getStats()
{
    cout << name << "'s Level: " << level << endl;
    cout << name << "'s HP: " << health << endl;
    cout << name << "'s ATK: " << attack << endl;
    cout << name << "'s DEF: " << defense << endl;
    cout << name << "'s SPD: " << speed << endl;
    cout << name << "'s MGK ATK: " << magic_attack << endl;
    cout << name << "'s MGK DEF: " << magic_defense << endl;
    cout << name << "'s EXP: " << exp << endl;
}


    /*
        Items:
        Potions (Lvl 1-5) (Heals by a certain amt.)
        Defensive Flasks (Lvl 1-3) (Ups true DEF by certain amt.)
        Offensive Flasks (Lvl 1-3) (Ups true ATK by certain amt.)
        Pouch of Sand (Throws sand in the enemy's eyes. May cause the enemy to miss an attack.)
        Armor/Weapons (Boosts certain stats) (LATER, NOT IN FIRST EDITION OF GAME)
    */

    /*
        Purity Items: (LATER, NOT IN FIRST EDITION OF GAME)
        (APPEAR IN OTHER SLOTS, DO NOT TAKE UP INVENTORY SPACE)
        Soul of the Plains (Boosts speed by 10) [Obtainable by defeating the Plains boss]
        Heart of the Forest (Boosts both Magic ATK and Magic DEF by 5) [Obtainable by defeating the Forest boss]
        Will of the Mountain (Boosts ATK by 5 and DEF by 10) [Obtainable by defeats the Mountains boss]
        Crown of the King (Congratulations!!) [Obtainable by defeating the King]
    */
void Inventory::getInventory()
{
    cout << "[1. " << item_1 << " (" << item_1_quantity << "/10) ]  [2. " << item_2 << " (" << item_2_quantity << "/10) ]" << endl;
    cout << "[3. " << item_3 << " (" << item_3_quantity << "/10) ]  [4. " << item_4 << " (" << item_4_quantity << "/10) ]" << endl;
    cout << "[5. " << item_5 << " (" << item_5_quantity << "/10) ]  [6. " << item_6 << " (" << item_6_quantity << "/10) ]" << endl;
    cout << "[7. " << item_7 << " (" << item_7_quantity << "/10) ]  [8. " << item_8 << " (" << item_8_quantity << "/10) ]" << endl;
    cout << "[9. " << item_9 << " (" << item_9_quantity << "/10) ]  [10. " << item_10 << " (" << item_10_quantity << "/10) ]" << endl;
}