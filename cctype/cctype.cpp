/* File: cctype.cpp
 * ----------------
 * This file implements the cctype.h interface.
 */

#include <set>
#include <string>
#include <algorithm>
#include "cctype.h"

using std::set;
using std::string;
using std::back_inserter;

extern const set<char> DIGIT_SET = setFromString("0123456789");
extern const set<char> LOWER_SET = setFromString("abcdefghijklmnopqrstuvwxyz");
extern const set<char> UPPER_SET = setFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
extern const set<char> PUNCT_SET = setFromString("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}");
extern const set<char> SPACE_SET = setFromString(" \t\v\f\n\r");
extern const set<char> XDIGIT_SET = setFromString("0123456789ABCDEFabcdef");
extern const set<char> ALPHA_SET = setUnion(LOWER_SET, UPPER_SET);
extern const set<char> ALNUM_SET = setUnion(ALPHA_SET, DIGIT_SET);
extern const set<char> PRINT_SET = setUnion(setUnion(ALNUM_SET, PUNCT_SET), SPACE_SET);

bool isdigit(char ch) {
    return DIGIT_SET.find(ch) != DIGIT_SET.end();
}

bool islower(char ch) {
    return LOWER_SET.find(ch) != LOWER_SET.end();
}

bool isupper(char ch) {
    return UPPER_SET.find(ch) != UPPER_SET.end();
}

bool ispunct(char ch) {
    return PUNCT_SET.find(ch) != PUNCT_SET.end();
}

bool isspace(char ch) {
    return SPACE_SET.find(ch) != SPACE_SET.end();
}

bool isxdigit(char ch) {
    return XDIGIT_SET.find(ch) != XDIGIT_SET.end();
}

bool isalpha(char ch) {
    return ALPHA_SET.find(ch) != ALPHA_SET.end();
}

bool isalnum(char ch) {
    return ALNUM_SET.find(ch) != ALNUM_SET.end();
}

bool isprint(char ch) {
    return PRINT_SET.find(ch) != PRINT_SET.end();
}

set<char> setFromString(const string& str) {
    set<char> set;
    for (string::size_type i = 0; i != str.length(); ++i)
        set.insert(str[i]);
    return set;
}

set<char> setUnion(const set<char>& first, const set<char>& second) {
    set<char> dest = first;
    dest.insert(second.cbegin(), second.cend());
    return dest;
}
