#include <chrono>
using namespace std::chrono_literals;
struct Settings
{
    std::chrono::duration <double, std::milli> text_speed = 2000ms;
    void showGameSettings();
    private:
};