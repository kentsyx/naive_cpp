/* File: strlib.h
 * --------------
 * This interface exports some handy functions for manupilating strings.
 */

#ifndef STRLIB_H
#define STRLIB_H

#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include "error.h"

typedef std::string::size_type size_type;

int countSpaces(const std::string);

bool startsWith(const std::string, const std::string);

bool endsWith(const std::string, const std::string);

std::string repeatChar(char, int);

std::string reverse(std::string);

bool isDigitString(const std::string);

bool equalsIgnoreCases(const std::string, const std::string);

std::string toUpperCaseInPlace(std::string& str);

std::string toUpperCase(std::string str);

std::string toLowerCaseInPlace(std::string& str);

std::string toLowerCase(std::string str);

bool isPalindrome_bad(const std::string);

bool isPalindrome_recursive(const std::string, int, int);

bool isPalindrome(const std::string);

/* Remove any white space characters from the beginning
 * and end of the argument. */
std::string trim(std::string);

/* A fun illustration */

class EnglishToPigLatin {
public:
    bool isVowel(char);
    int findFirstVowel(std::string);
    std::string wordToPigLatin(std::string);
    std::string lineToPigLatin(std::string);

private:
    std::string line;

};

int stringToInteger(std::string);

std::string integerToString(int);

#endif // STRLIB_H
