#ifndef SLEEPFOR_HPP
#define SLEEPFOR_HPP
#include <chrono>
#include "settings.hpp"
using namespace std::chrono_literals;
void sleepFor(std::chrono::duration <double, std::milli>);
#endif