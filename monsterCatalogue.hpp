#ifndef MONSTERCATALOGUE_HPP
#define MONSTERCATALOGUE_HPP
#include <string>
struct MonsterCatalogue
{
    std::string area_name;
    std::string monster_name;
    unsigned int base_hp;
    unsigned int base_atk;
    unsigned int base_def;
    unsigned int base_speed;
    unsigned int base_mgk_atk;
    unsigned int base_mgk_def;
    unsigned int base_level;

    int printMonsterCatalogueMenu();
    int getMonsterCataloguePage(int);
};

struct Monsters
{
    public:

    // MonsterCatalogue Plains{.area_name = "Plains"};

    // MonsterCatalogue Forest{.area_name = "Forest"};

    // MonsterCatalogue Mountains{.area_name = "Mountains"};

    // MonsterCatalogue Castle{.area_name = "Castle"};
};

#endif