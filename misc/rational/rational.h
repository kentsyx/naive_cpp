/* File: rational.h
 * ----------------
 * This interface exports the class for representing rational numbers.
 */


#include <iostream>
#include <string>

class Rational {
    friend Rational operator +(Rational, Rational);
    friend Rational operator -(Rational, Rational);
    friend Rational operator *(Rational, Rational);
    friend Rational operator /(Rational, Rational);

public:
    Rational();
    Rational(int);
    Rational(int, int);
    std::string toString();

private:
    int num;
    int den;
    int gcd(int, int);
};

std::ostream& operator <<(std::ostream&, Rational);

Rational operator +(Rational, Rational);

Rational operator -(Rational, Rational);

Rational operator *(Rational, Rational);

Rational operator /(Rational, Rational);

#ifndef RATIONAL_H
#define RATIONAL_H

#endif // RATIONAL_H
