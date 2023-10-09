#include <iostream>
#include <chrono>
#include <thread>

#include "settings.hpp"
#include "sleepFor.hpp"
using namespace std;
using namespace std::chrono_literals;
void sleepFor(std::chrono::duration <double, milli> text_speed)
{
    this_thread::sleep_for(text_speed);
}