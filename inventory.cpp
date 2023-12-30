#include "inventory.hpp"
#include <string>
using namespace std;

//--------------------------------------[Constructors]-----------------------------------------

Inventory::Inventory()
{
    name_ = "";
    quantity_ = 0;
}

Inventory::Inventory(string name)
{
    name_ = name;
    quantity_ = 0;
}

// -------------------------------------[Interfaces]-------------------------------------------
vector<Inventory> Inventory::createInventory()
{
    vector<Inventory> inventory;
    Inventory potion1("Potion Level 1");
    Inventory potion2("Potion Level 2");
    Inventory potion3("Potion Level 3");
    Inventory defense_flask1("Defensive Flask Level 1");
    Inventory defense_flask2("Defensive Flask Level 2");
    Inventory defense_flask3("Defensive Flask Level 3");
    Inventory offense_flask1("Offensive Flask Level 1");
    Inventory offense_flask2("Offensive Flask Level 2");
    Inventory offense_flask3("Offensive Flask Level 3");
    Inventory sand("Pouch of Sand");
    inventory.push_back(potion1);
    inventory.push_back(potion2);
    inventory.push_back(potion3);
    inventory.push_back(defense_flask1);
    inventory.push_back(defense_flask2);
    inventory.push_back(defense_flask3);
    inventory.push_back(offense_flask1);
    inventory.push_back(offense_flask2);
    inventory.push_back(offense_flask3);
    inventory.push_back(sand);

    return inventory;
}

// ------------------------------[Getters]------------------------------
string Inventory::getItemName()
{
    return name_;
}

int Inventory::getItemQuantity()
{
    return quantity_;
}
