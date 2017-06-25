/* File: random.cpp
 * ----------------
 * This file implements the random.h interface.
 */

#include <cstdlib>
#include <cmath>
#include <ctime>
#include "random.h"

using std::rand;
using std::srand;
using std::floor;
using std::time;

/* Private function prototype */
void initRandomSeed();

int randomInteger(int low, int high) {
    initRandomSeed();
    double d = double(rand()) / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

double randomReal(double low, double high) {
    double d = double(rand()) / (double(RAND_MAX) + 1);
    double s = d * (high - low);
    return low + s;
}

bool randomChance(double p) {
    return randomReal(0, 1) < p;
}

void setRandomSeed(int seed) {
    initRandomSeed();
    srand(seed);
}

void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
        srand(int(time(NULL)));
        initialized = true;
    }
}
