#include <iostream>

#include "monsterCatalogue.hpp"
#include "sleepFor.hpp"
#include "settings.hpp"

using namespace std;


int MonsterCatalogue::printMonsterCatalogueMenu()
{
    int input;
    cout << "[1. Plains Enemies]" << endl;
    cout << "[2. Forest Enemies]" << endl;
    cout << "[3. Mountain Enemies]" << endl;
    cout << "[4. Castle Enemies]" << endl;
    cout << "[5. Boss Enemies]" << endl;
    cin >> input;
    return input;
}

int MonsterCatalogue::getMonsterCataloguePage(int input)
{
    switch(input)
    {
    case 1:
        cout << "Plains:" << endl << endl;
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    default:
        break;
    }
    return 0;
}