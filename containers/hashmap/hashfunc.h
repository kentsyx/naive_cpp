/* File: hashfunc.h
 * ----------------
 * This file exports several overloaded hash functions.
 */

#ifndef HASHFUNC_H
#define HASHFUNC_H

#include <string>

extern const int HASH_SEED;
extern const int HASH_MULTIPLIER;
extern const int HASH_MASK;

int hashCode(const std::string&);
int hashCode(int);
int hashCode(char);
int hashCode(long);
int hashCode(double);

#endif // HASHFUNC_H
