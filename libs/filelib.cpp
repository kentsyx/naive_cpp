/* File: filelib.cpp
 * -----------------
 * This file implements the filelib.h interface.
 */

#include <iostream>
#include <fstream>
#include <string>

using std::istream;
using std::ostream;
using std::ifstream;
using std::string;
using std::endl;
using std::getline;

string propmtUserForFile(ifstream& infile, istream& is, ostream& os, string prompt) {
    while (true) {
        os << prompt;
        string filename;
        getline(is, filename);
        ifstream infile;
        infile.open(filename.c_str());
        if (!infile.fail())
            return filename;
        infile.clear();
        os << "Can not open file. Try again. " << endl;
        if (prompt == "")
            os << "Input file: ";
    }
}
