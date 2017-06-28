/* File: strlib.h
 * --------------
 * This file implements the strlib.h interface.
 */

#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include "error.h"

using std::string;
using std::isalpha;
using std::tolower;
using std::toupper;
using std::istringstream;
using std::ostringstream;
using std::ws;

typedef string::size_type size_type;

int countSpaces(const string str) {
    int nSpaces = 0;
    for (size_type i = 0; i != str.length(); ++i) {
        if (str[i] == ' ')
            nSpaces += 1;
    }
    return nSpaces;
}

bool startsWith(const string str, const string prefix) {
    if (str.length() < prefix.length())
        return false;
    for (size_type i = 0; i != prefix.length(); ++i) {
        if (str[i] != prefix[i])
            return false;
        }
    return true;
}

bool endsWith(const string str, const string suffix) {
    if (str.length() < suffix.length())
        return false;
    for (size_type i = suffix.length() - 1; i != 0; --i) {
        if (str[i + str.length() - suffix.length()] != suffix[i])
            return false;
    }
    return true;
}

string repeatChar(char ch, int n) {
    string result = "";
    for (size_type i = 0; i != n; ++i)
        result += ch;
    return result;
}

string reverse(string str) {
    string result = "";
    for (size_type i = str.length() - 1; i != 0; --i)
        result += str[i];
    return result;
}

bool isDigitString(const string str) {
    if (str.length() == 0)
        return false;
    for (size_type i = 0; i != str.length(); ++i)
        if (!isalpha(str[i]))
            return false;
    return true;
}

bool euqalsIgnoreCases(const string s1, const string s2) {
    if (s1.length() != s2.length())
        return false;
    for (size_type i = 0; i != s1.length(); ++i) {
        if (tolower(s1[i]) != tolower(s2[i]))
            return false;
    }
    return true;
}

string toUpperCaseInPlace(string& str) {
    for (size_type i = 0; i != str.length(); ++i)
        str[i] = toupper(str[i]);
    return str;
}

string toUpperCase(string str) {
    str = toUpperCaseInPlace(str);
    return str;
}

string toLowerCaseInPlace(string& str) {
    for (size_type i = 0; i != str.length(); ++i)
        str[i] = tolower(str[i]);
    return str;
}

string toLowerCase(string str) {
    str = toLowerCaseInPlace(str);
    return str;
}

bool isPalindrome_bad(const string str) {
    return str == reverse(str);
}

bool isPalindrome_recursive(const string str, int start, int end) {
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome_recursive(str, 0, str.length() - 1);
}

bool isPalindrome(const string str) {
    size_type n = str.length();
    for (size_type i = 0; i < n / 2; ++i)
        if (str[i] != str[n - i - 1])
            return false;
    return true;
}

string trim(string str) {
    int b_marker = 0;
    while (str[b_marker] == ' ')
        ++b_marker;
    int e_marker = str.length() - 1;
    while (str[e_marker] == ' ')
        --e_marker;
    return str.substr(b_marker, e_marker - b_marker + 1);
}

int stringToInteger(string str) {
    istringstream stream(str);
    int value;
    stream >> value >> ws;
    if (stream.fail() || !stream.eof())
        error(" Illegal integer format. Please try again. ");
    return value;
}

string integerToString(int value) {
    ostringstream stream;
    stream << value;
    return stream.str();
}
