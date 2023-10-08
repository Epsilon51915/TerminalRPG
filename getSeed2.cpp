#include <iostream>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

system_clock::time_point previous = high_resolution_clock::now();

unsigned int getSeed()
{
system_clock::time_point lap = high_resolution_clock::now();
duration<double, micro> seed = lap - previous;
previous = lap;

return static_cast<unsigned int>(seed.count());
}

int main(){

    cout << "Enter an input" << endl;
    int input;
    cin >> input;

    unsigned int seed = getSeed();

    cout << "Time for input: " << seed << endl;

    return 0;
}