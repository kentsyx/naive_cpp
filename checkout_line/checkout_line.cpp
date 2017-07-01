/* File: checkout_line.cpp
 * -----------------------
 * This file implements the checkout_line.h interface.
 */

#include <queue>
#include <iostream>
#include <iomanip>
#include "random.h"
#include "checkout_line.h"

using std::queue;
using std::ostream;
using std::setprecision;
using std::endl;
using std::fixed;
using std::setw;

extern const int SIMULATION_TIME = 2000;
extern const double ARRIVAL_PROBABILITY = 0.05;
extern const int MIN_SERVICE_TIME = 5;
extern const int MAX_SERVICE_TIME = 15;

void runSimulation(int& nServed, int& totalWait, int& totalLength) {
    queue<int> queue;
    int timeRemaining = 0;
    nServed = 0;
    totalWait = 0;
    totalLength = 0;
    for (int t = 0; t != SIMULATION_TIME; ++t) {
        if (randomChance(ARRIVAL_PROBABILITY)) {
            queue.push(t);
        }
        else if (timeRemaining > 0) {
            --timeRemaining;
        }
        else if (!queue.empty()) {
            totalWait += t - queue.front();
            queue.pop();
            ++nServed;
            timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
        }
        totalLength += queue.size();
    }
}

void printReport(int nServed, int totalWait, int totalLength, ostream& os) {
    os << "Simulation results given the following constants: " << endl;
    os << fixed << setprecision(2);
    os << "  SIMULATION_TIME:     " << setw(4) << SIMULATION_TIME << endl;
    os << "  ARRIVAL_PROBABILITY: " << setw(4) << ARRIVAL_PROBABILITY << endl;
    os << "  MIN_SERVICE_TIME:    " << setw(4) << MIN_SERVICE_TIME << endl;
    os << "  MAX_SERVICE_TIME:    " << setw(4) << MAX_SERVICE_TIME << endl;
    os << endl;
    os << "Customers served:      " << setw(4) << nServed << endl;
    os << "Average waiting time:  " << setw(7) << double(totalWait) / nServed << endl;
    os << "Average queue length:  " << setw(7) << double(totalLength) / SIMULATION_TIME << endl;
}
