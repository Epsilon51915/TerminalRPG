#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <vector>

using namespace std;

class Inventory
{
    private:
       string name_;
       int quantity_; 

    public:
//-------------------------[Constructors]--------------------------
        Inventory();
        Inventory(string);

//-------------------------[Interfaces]----------------------------
        vector<Inventory> createInventory();

// ------------------------[Getters]-------------------------------
        string getItemName();
        int getItemQuantity();

};

#endif