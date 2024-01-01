#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <vector>

class Inventory
{
    private:
       std::string name_;
       int quantity_; 

    public:
//-------------------------[Constructors]--------------------------
        Inventory();
        Inventory(std::string);

//-------------------------[Interfaces]----------------------------
        std::vector<Inventory> createInventory();

// ------------------------[Getters]-------------------------------
        std::string getItemName();
        int getItemQuantity();

};

#endif