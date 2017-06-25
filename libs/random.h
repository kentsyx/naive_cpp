/* File: random.h
 * --------------
 * This interface exports functions for generating pseudo-random numbers.
 */

#ifndef RANDOM_H
#define RANDOM_H

int randomInteger(int, int);

double randomReal(double, double);

bool randomChance(double);

void setRandomSeed(int);

#endif // RANDOM_H
