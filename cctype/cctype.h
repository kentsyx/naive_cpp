/* File: cctype.h
 * --------------
 * This interface exports the functions that simulates the <cctype> library using a set of characters.
 */

#include <set>
#include <string>

extern const std::set<char> DIGIT_SET;
extern const std::set<char> LOWER_SET;
extern const std::set<char> UPPER_SET;
extern const std::set<char> PUNCT_SET;
extern const std::set<char> SPACE_SET;
extern const std::set<char> XDIGIT_SET;
extern const std::set<char> ALPHA_SET;
extern const std::set<char> ALNUM_SET;
extern const std::set<char> PRINT_SET;

bool isdigit(char);
bool islower(char);
bool isupper(char);
bool ispunct(char);
bool isspace(char);
bool isxdigit(char);
bool isalpha(char);
bool isalnum(char);
bool isprint(char);

std::set<char> setFromString(const std::string&);

std::set<char> setUnion(const std::set<char>&, const std::set<char>&);

#ifndef CCTYPE_H
#define CCTYPE_H

#endif // CCTYPE_H
