/* File: hashfunc.cpp
 * ------------------
 * This file implements the hashfunc.h interface.
 */

#include <string>
#include "hashfunc.h"

using std::string;

extern const int HASH_SEED = 5381;
extern const int HASH_MULTIPLIER = 33;
extern const int HASH_MASK = unsigned(-1) >> 1;

int hashCode(const string& key) {
    unsigned hash = HASH_SEED;
    int n = key.length();
    for (int i = 0; i != n; i++) {
        hash = HASH_MULTIPLIER * hash + key[i];
    }
    return int(hash & HASH_MASK);
}

int hashCode(int key) {
    ;
}

int hashCode(char key) {
    ;
}

int hashCode(long key) {
    ;
}

int hashCode(double key) {
    ;
}

