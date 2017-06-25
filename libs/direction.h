/* File: direction.h
 * ------------------
 * This interface exports an enumerated type called Direction whose
 * elements are the four compass points: NORTH, EAST, SOUTH and WEST.
 */

#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

enum Direction {NORTH, EAST, SOUTH, WEST};

Direction leftFrom(Direction);

Direction rightFrom(Direction);

std::string directionToString(Direction);

#endif // DIRECTION_H
