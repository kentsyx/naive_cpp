/* File: point.h
 * -------------
 * This interface exports the Point class, which represents a point on
 * the two-dimensional integer grid.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

class Point {
    friend bool operator ==(Point, Point);
    friend Point operator +(Point, Point);
    friend Point operator -(Point, Point);
public:
    Point();
    Point(int, int);
    int getX() const;
    int getY() const;
    std::string toString();

private:
    int x;
    int y;
};

std::ostream& operator <<(std::ostream&, Point);

bool operator ==(Point, Point);

bool operator !=(Point, Point);

Point operator +(Point, Point);

Point operator -(Point, Point);

#endif // POINT_H
