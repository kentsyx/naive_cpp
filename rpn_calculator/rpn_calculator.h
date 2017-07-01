/* File: rpn_calculator.h
 * ----------------------
 * rpn_calculator interface.
 */

#include <iostream>
#include <stack>

void applyOperator(char, std::stack<double>&, std::ostream&);

void helpCommand(std::ostream&);

void runSimulation(std::ostream&, std::istream&);

#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#endif // RPN_CALCULATOR_H
