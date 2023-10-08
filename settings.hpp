// Prevents from re-including duplicate files, such as duplicate #include <chrono>'s, <iostream>'s, etc.

#ifndef SETTINGS_HPP
#define SETTINGS_HPP
#include <chrono>
using namespace std::chrono_literals;
struct Settings
{
    std::chrono::duration <double, std::milli> text_speed = 2000ms;
    void showGameSettings();
    private:
};
#endif