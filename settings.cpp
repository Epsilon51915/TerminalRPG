#include <iostream>
#include <iomanip>

#include "settings.hpp"

using namespace std;

void Settings::showGameSettings(){


    cout << "Text speed: " << fixed << setprecision(1) << text_speed.count() / 1000 << " seconds." << endl;
    
    return;
}