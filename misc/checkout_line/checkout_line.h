/* File: checkout_line.h
 * ---------------------
 * This interface exports the functions for simulating a
 * checkout line like the ones you encounter say, in a
 * supermarket.
 */

#ifndef CHECKOUT_LINE_H
#define CHECKOUT_LINE_H

#include <iostream>

void runSimulation(int&, int&, int&);
void printReport(int, int, int, std::ostream&);

extern const int SIMULATION_TIME;
extern const double ARRIVAL_PROBABILITY;
extern const int MIN_SERVICE_TIME;
extern const int MAX_SERVICE_TIME;

#endif // CHECKOUT_LINE_H
