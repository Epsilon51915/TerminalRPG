#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>

struct Enemy
{
    std::string enemy_name;
    unsigned int base_hp;
    unsigned int base_atk;
    unsigned int base_def;
    unsigned int base_speed;
    unsigned int base_mgk_atk;
    unsigned int base_mgk_def;
    unsigned int base_level;
};

struct EnemyBaseStats
{
    // Plains Enemies
    Enemy SmallRock{.enemy_name = "Small Rock", .base_hp = 10, .base_atk = 0, .base_def = 5, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 1};
    Enemy MediumRock{.enemy_name = "Medium Rock", .base_hp = 15, .base_atk = 0, .base_def = 7, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 1};
    Enemy LargeRock{.enemy_name = "Large Rock", .base_hp = 20, .base_atk = 0, .base_def = 10, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 2};
    Enemy Snake{.enemy_name = "Snake", .base_hp = 6, .base_atk = 2, .base_def = 2, .base_speed = 7, .base_mgk_atk = 1, .base_mgk_def = 1, .base_level = 1};
    Enemy ForestCreature{.enemy_name = "Forest Creature", .base_hp = 12, .base_atk = 1, .base_def = 3, .base_speed = 5, .base_mgk_atk = 4, .base_mgk_def = 6, .base_level = 2};

    // Forest Enemies
    Enemy MediumRock{.enemy_name = "Medium Rock", .base_hp = 15, .base_atk = 0, .base_def = 7, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 1};
    Enemy LargeRock{.enemy_name = "Large Rock", .base_hp = 20, .base_atk = 0, .base_def = 10, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 2};
    Enemy Bear{.enemy_name = "Bear", .base_hp = 14, .base_atk = 6, .base_def = 6, .base_speed = 5, .base_mgk_atk = 2, .base_mgk_def = 3, .base_level = 2};
    Enemy Spider{.enemy_name = "Spider", .base_hp = 8, .base_atk = 3, .base_def = 1, .base_speed = 11, .base_mgk_atk = 5, .base_mgk_def = 7, .base_level = 2};
    Enemy Tree{.enemy_name = "Tree", .base_hp = 17, .base_atk = 5, .base_def = 9, .base_speed = 0, .base_mgk_atk = 8, .base_mgk_def = 10, .base_level = 3};
    Enemy AngryTree{.enemy_name = "Angry Tree", .base_hp = 17, .base_atk = 9, .base_def = 5, .base_speed = 0, .base_mgk_atk = 10, .base_mgk_def = 7, .base_level = 3};

    // Mountain Enemies
    Enemy LargeRock{.enemy_name = "Large Rock", .base_hp = 20, .base_atk = 0, .base_def = 10, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 2};
    Enemy Boulder{.enemy_name = "Boulder", .base_hp = 35, .base_atk = 0, .base_def = 50, .base_speed = 0, .base_mgk_atk = 0, .base_mgk_def = 0, .base_level = 10};
    Enemy RockSnake{.enemy_name = "Rock Snake", .base_hp = 13, .base_atk = 7, .base_def = 9, .base_speed = 6, .base_mgk_atk = 3, .base_mgk_def = 4, .base_level = 4};
    Enemy Spider{.enemy_name = "Spider", .base_hp = 8, .base_atk = 3, .base_def = 1, .base_speed = 11, .base_mgk_atk = 5, .base_mgk_def = 7, .base_level = 2};
    Enemy Golem{.enemy_name = "Golem", .base_hp = 25, .base_atk = 10, .base_def = 15, .base_speed = 5, .base_mgk_atk = 10, .base_mgk_def = 5, .base_level = 5};
    Enemy SkeletonClimber{.enemy_name = "Skeleton Climber", .base_hp = 15, .base_atk = 8, .base_def = 5, .base_speed = 14, .base_mgk_atk = 13, .base_mgk_def = 16, .base_level = 4};
    Enemy OzoneFeaster{.enemy_name = "Ozone Feaster", .base_hp = 20, .base_atk = 11, .base_def = 13, .base_speed = 17, .base_mgk_atk = 14, .base_mgk_def = 18, .base_level = 5};

    // Castle Enemies
    Enemy WeirdCollegeStudent{.enemy_name = "Weird College Student", .base_hp = 1000, .base_atk = 0, .base_def = 10000, .base_speed = 10000, .base_mgk_atk = 0, .base_mgk_def = 10000, .base_level = 10000};
    Enemy ForestCreaturePlus{.enemy_name = "Forest Creature +", .base_hp = 27, .base_atk = 8, .base_def = 14, .base_speed = 24, .base_mgk_atk = 19, .base_mgk_def = 22, .base_level = 5};
    Enemy BearPlus{.enemy_name = "Bear +", .base_hp = 34, .base_atk = 17, .base_def = 19, .base_speed = 20, .base_mgk_atk = 12, .base_mgk_def = 14, .base_level = 5};
    Enemy AngryTreePlus{.enemy_name = "Angry Tree +", .base_hp = 36, .base_atk = 22, .base_def = 21, .base_speed = 0, .base_mgk_atk = 27, .base_mgk_def = 31, .base_level = 5};
    Enemy SpiderPlus{.enemy_name = "Spider +", .base_hp = 26, .base_atk = 14, .base_def = 11, .base_speed = 28, .base_mgk_atk = 27, .base_mgk_def = 24, .base_level = 5};
    Enemy OzoneFeasterPlus{.enemy_name = "Ozone Feaster +", .base_hp = 45, .base_atk = 30, .base_def = 32, .base_speed = 16, .base_mgk_atk = 29, .base_mgk_def = 32, .base_level = 6};
    Enemy LesserDemon{.enemy_name = "Lesser Demon", .base_hp = 36, .base_atk = 17, .base_def = 21, .base_speed = 26, .base_mgk_atk = 25, .base_mgk_def = 28, .base_level = 4};
    Enemy Demon{.enemy_name = "Demon", .base_hp = 48, .base_atk = 32, .base_def = 41, .base_speed = 31, .base_mgk_atk = 37, .base_mgk_def = 43, .base_level = 7};

};

#endif