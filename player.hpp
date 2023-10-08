#include <string>

struct Player
{
public:
    std::string name;
    unsigned int level;
    unsigned int health;
    unsigned int attack;
    unsigned int defense;
    unsigned int speed;
    unsigned int magic_attack;
    unsigned int magic_defense;
    unsigned int exp;
    
    Inventory item_1;
    Inventory item_2;
    Inventory item_3;
    Inventory item_4;
    Inventory item_5;
    Inventory item_6;
    Inventory item_7;
    Inventory item_8;
    Inventory item_9;
    Inventory item_10;
    Inventory item_1_quantity;
    Inventory item_2_quantity;
    Inventory item_3_quantity;
    Inventory item_4_quantity;
    Inventory item_5_quantity;
    Inventory item_6_quantity;
    Inventory item_7_quantity;
    Inventory item_8_quantity;
    Inventory item_9_quantity;
    Inventory item_10_quantity;
    
Player (const std::string& name);

void sayHello();
void getLore();
void getStats();
};

struct Inventory
{
    public:
    std::string item_1 = "";
    std::string item_2 = "";
    std::string item_3 = "";
    std::string item_4 = "";
    std::string item_5 = "";
    std::string item_6 = "";
    std::string item_7 = "";
    std::string item_8 = "";
    std::string item_9 = "";
    std::string item_10 = "";
    int item_1_quantity = 0;
    int item_2_quantity = 0;
    int item_3_quantity = 0;
    int item_4_quantity = 0;
    int item_5_quantity = 0;
    int item_6_quantity = 0;
    int item_7_quantity = 0;
    int item_8_quantity = 0;
    int item_9_quantity = 0;
    int item_10_quantity = 0;
    void getInventory();
};