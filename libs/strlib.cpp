/* File: strlib.h
 * --------------
 * This file implements the strlib.h interface.
 */

#include <string>
#include <cctype>

using std::string;
using std::isalpha;
using std::tolower;
using std::toupper;

typedef string::size_type size_type;

int countSpaces(string str) {
    int nSpaces = 0;
    for (size_type i = 0; i != str.length(); ++i) {
        if (str[i] == ' ')
            nSpaces += 1;
    }
    return nSpaces;
}

bool startsWith(string str, string prefix) {
    if (str.length() < prefix.length())
        return false;
    for (size_type i = 0; i != prefix.length(); ++i) {
        if (str[i] != prefix[i])
            return false;
        }
    return true;
}

bool endsWith(string str, string suffix) {
    ;
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

bool isDigitString(string str) {
    if (str.length() == 0)
        return false;
    for (size_type i = 0; i != str.length(); ++i)
        if (!isalpha(str[i]))
            return false;
    return true;
}

bool euqalsIgnoreCases(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;
    for (size_type i = 0; i != s1.length(); ++i) {
        if (tolower(s1[i] != s2[i]))
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

string tolowerCase(string str) {
    str = toLowerCaseInPlace(str);
    return str;
}

bool isPalindrome_bad(string str) {
    return str == reverse(str);
}

bool isPalindrome_recur(string str) {
    ;
}

bool isPalindrome(string str) {
    size_type n = str.length();
    for (size_type i = 0; i < n / 2; ++i)
        if (str[i] != str[n - i - 1])
            return false;
    return true;
}
























