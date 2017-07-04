/* File: point.cpp
 * ---------------
 * This file implements the point.h interface.
 */

#include <iostream>
#include <string>
#include "strlib.h"
#include "point.h"

using std::ostream;
using std::string;

Point::Point() : x(0), y(0) {}

Point::Point(int xc, int yc) : x(xc), y(yc) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

string Point::toString() {
    return "(" + integerToString(x) + ", " + integerToString(y) + ")";
}

ostream& operator <<(ostream& os, Point p) {
    return os << p.toString();
}

bool operator ==(Point p1, Point p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}

bool operator !=(Point p1, Point p2) {
    return !(p1 == p2);
}

Point operator +(Point p1, Point p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator -(Point p1, Point p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}
