/* File: direction.cpp
 * -------------------
 * This file implements the direction.h interface.
 */

#include <iostream>
#include <string>
#include "direction.h"

using std::ostream;
using std::string;

Direction leftFrom(Direction dir) {
    return Direction((dir + 3) % 4);
}

Direction rightFrom(Direction dir) {
    return Direction((dir + 1) % 4);
}

string directionToString(Direction dir) {
    switch (dir) {
    case NORTH: return "NORTH";
    case EAST: return "EAST";
    case SOUTH: return "SOUTH";
    case WEST: return "WEST";
    default: return "???";
    }
}

ostream& operator <<(ostream& os, Direction dir) {
    return os << directionToString(dir);
}

Direction operator ++(Direction dir) {
    return Direction(dir + 1);
}

Direction operator ++(Direction dir, int dummy) {
    Direction old = dir;
    dir = Direction(dir + 1);
    return old;
}
