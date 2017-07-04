/* File: direction.h
 * ------------------
 * This interface exports an enumerated type called Direction whose
 * elements are the four compass points: NORTH, EAST, SOUTH and WEST.
 */

#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>
#include <string>

enum Direction {NORTH, EAST, SOUTH, WEST};

Direction leftFrom(Direction);

Direction rightFrom(Direction);

std::string directionToString(Direction);

std::ostream& operator <<(std::ostream&, Direction);

Direction operator ++(Direction); // prefix ++

Direction operator ++(Direction, int); // suffix ++

#endif // DIRECTION_H
