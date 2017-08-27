/* File: rational.cpp
 * ------------------
 * This file implements the Rational class.
 */

#include <iostream>
#include <string>
#include <cmath>
#include "error.h"
#include "strlib.h"
#include "rational.h"

using std::ostream;
using std::string;

Rational::Rational() : num(0), den(1) {}

Rational::Rational(int n) : num(n), den(1) {}

Rational::Rational(int x, int y) {
    if (y == 0)
        error("The denominator can not be zero.");
    if (x == 0) {
        num = 0;
        den = 1;
    } else {
        int g = gcd(x, y);
        num = x / g;
        den = abs(y) / g;
        if (y < 0) num = -num;
    }
}

string Rational::toString() {
    if (den == 1)
        return integerToString(num);
    return integerToString(num) + "/" + integerToString(den);
}

ostream& operator <<(ostream& os, Rational r) {
    return os << r.toString();
}

Rational operator +(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator -(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den - r1.den * r2.num, r1.den * r2.den);
}

Rational operator *(Rational r1, Rational r2) {
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator /(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den, r1.den * r2.num);
}

int Rational::gcd(int x, int y) {
    int rem = x % y;
    while (rem != 0) {
        x = y;
        y = rem;
        rem = x % y;
    }
    return y;
}
