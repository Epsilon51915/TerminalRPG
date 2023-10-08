#include <string>

struct PlayerItem
{
    std::string name;
    unsigned int quantity;
};

struct Inventory
{
    public:
    PlayerItem potion1{.name = "Potion Level 1", .quantity = 0};
    PlayerItem potion2{.name = "Potion Level 2", .quantity = 0};
    PlayerItem potion3{.name = "Potion Level 3", .quantity = 0};
    // std::string item_1 = "";
    // std::string item_2 = "";
    // std::string item_3 = "";
    // std::string item_4 = "";
    // std::string item_5 = "";
    // std::string item_6 = "";
    // std::string item_7 = "";
    // std::string item_8 = "";
    // std::string item_9 = "";
    // std::string item_10 = "";
    // int item_1_quantity = 0;
    // int item_2_quantity = 0;
    // int item_3_quantity = 0;
    // int item_4_quantity = 0;
    // int item_5_quantity = 0;
    // int item_6_quantity = 0;
    // int item_7_quantity = 0;
    // int item_8_quantity = 0;
    // int item_9_quantity = 0;
    // int item_10_quantity = 0;
    void printInventory();
};



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
    
    Inventory inventory;
Player (const std::string& name);

void sayHello();
void printLore();
void printStats();
};