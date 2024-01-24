#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>

class Item
{
    private:
       std::string name_;
       int quantity_; 
       /*int max_quantity_;
       std::string description_;
       int hp_heal_, def_raise, atk_raise;*/
       // Potion Level 1, 2, 3, Defensive/Offensive Flask Level 1-3, Pouch of Sand

    public:
//-------------------------[Constructors]--------------------------
        Item();
        Item(std::string);

// ------------------------[Getters]-------------------------------
        std::string getItemName();
        int getItemQuantity();

};

#endif