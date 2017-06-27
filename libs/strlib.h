/* File: strlib.h
 * --------------
 * This interface exports some handy functions for manupilating strings.
 */

#ifndef STRLIB_H
#define STRLIB_H

#include <string>
#include <cctype>

typedef std::string::size_type size_type;

int countSpaces(std::string);

bool startsWith(std::string, std::string);

bool endsWith(std::string, std::string);

std::string repeatChar(char, int);

std::string reverse(std::string);

bool isDigitString(std::string);

bool equalsIgnoreCases(std::string, std::string);

std::string toUpperCaseInPlace(std::string& str);

std::string toUpperCase(std::string str);

std::string toLowerCaseInPlace(std::string& str);

std::string toLowerCase(std::string str);

bool isPalindrome_bad(std::string);

bool isPalindrome_recur(std::string);

bool isPalindrome(std::string);

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

#endif // STRLIB_H
