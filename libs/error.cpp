/* File: error.cpp
 * ----------------
 * This file implements the error.h interface.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "error.h"

using std::string;
using std::exit;
using std::cerr;
using std::endl;

void error(string msg) {
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
