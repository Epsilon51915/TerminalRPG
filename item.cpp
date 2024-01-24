#include "item.hpp"
#include <string>
using namespace std;

//--------------------------------------[Constructors]-----------------------------------------
Item::Item()
{
    name_ = "";
    quantity_ = 0;
}

Item::Item(string name)
{
    name_ = name;
    quantity_ = 0;
    /*if (name_ = )
    {

    }*/
}

// ------------------------------[Getters]------------------------------
string Item::getItemName()
{
    return name_;
}

int Item::getItemQuantity()
{
    return quantity_;
}
