/* File: rpn_calculator.cpp
 * ------------------------
 * This file implements the rpn_calculator.h interface.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include "../libs/error.h"
#include "../libs/strlib.h"
#include "rpn_calculator.h"

using std::istream;
using std::ostream;
using std::endl;
using std::string;
using std::getline;
using std::isdigit;
using std::toupper;
using std::stack;

void applyOperator(char op, stack<double>& operandStack, ostream& os) {
    double result;
    double rhs = operandStack.top();
    operandStack.pop();
    double lhs = operandStack.top();
    switch (op) {
    case '+': result = lhs + rhs; break;
    case '-': result = lhs - rhs; break;
    case '*': result = lhs * rhs; break;
    case '/': result = lhs / rhs; break;
    default: error("Illegal oprator.");
    }
    os << result << endl;
    operandStack.push(result);
}

void helpCommand(ostream& os) {
    os << "Enter expressions in Reverse Polish Notation, " << endl;
    os << "in which operators follow the operands to which" << endl;
    os << "they apply. Each line consists of a number, an " << endl;
    os << "operator, or one of the following commands" << endl;
    os << "Q - Quit the program." << endl;
    os << "H - Display help message. " << endl;
    os << "C - Clear the calculator stack. " << endl;
}

void runSimulation(ostream& os, istream& is) {
    os << "RPN calculator simulation. Type H for help. " << endl;
    stack<double> operandStack;
    while (true) {
        string line;
        os << "> ";
        getline(is, line);
        if (line.length() == 0)
            line = 'Q';
        char ch = toupper(line[0]);
        if (ch == 'Q') {
            break;
        } else if (ch == 'H') {
            helpCommand(os);
        } else if (ch == 'C') {
            while (!operandStack.empty())
                operandStack.pop();
        } else if (isdigit(ch)) {
            operandStack.push(stringToReal(line));
        } else
            applyOperator(ch, operandStack, os);
    }
}
