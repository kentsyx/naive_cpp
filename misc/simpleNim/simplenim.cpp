/* File: simplenim.cpp
 * -------------------
 * This file implements the simplenim.h interface
 */

#include <iostream>
#include <string>
#include "error.h"
#include "simplenim.h"

using std::istream;
using std::ostream;
using std::endl;
using std::getline;
using std::cin;
using std::cout;

extern const int N_COINS = 13;
extern const int MAX_MOVE = 3;
extern const int NO_GOOD_MOVE = -1;

Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

extern const Player STARTING_PlAYER = HUMAN;

void SimpleNim::printInstructions(ostream& os) {
    os << "Welcome to the game of Nim!" << endl;
    os << "In this game, there are " << N_COINS << " coins on the table." << endl;
    os << "You and I in turn are going to take 1 to " << MAX_MOVE << " coins from the " << endl;
    os << "pile. The one who takes the last remaining coin will lose." << endl;
    os << "Now Let's begin!" << endl;
}

void SimpleNim::play(ostream& os) {
    nCoins = N_COINS;
    whoseTurn = STARTING_PlAYER;
    while (nCoins > 1) {
        os << "There are now " << nCoins << " coins in the pile." << endl;
        if (whoseTurn == HUMAN) {
            nCoins -= getUserMove(cin, cout);
        }
        else {
            int nTaken = getComputerMove();
            os << "I'll take " << nTaken << " coins." << endl;
            nCoins -= nTaken;
        }
        whoseTurn = opponent(whoseTurn);
    }
    announceResult(os);
}

int SimpleNim::getComputerMove() {
    int nTaken = findGoodMove(nCoins);
    return (nTaken == NO_GOOD_MOVE) ? 1 : nTaken;
}

int SimpleNim::findGoodMove(int nCoins) {
    int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
    for (int nTaken = 1; nTaken != limit; ++nTaken) {
        if (isBadPosition(nCoins - nTaken))
            return nTaken;
    }
    return NO_GOOD_MOVE;
}

bool SimpleNim::isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return findGoodMove(nCoins) == NO_GOOD_MOVE;
}

int SimpleNim::getUserMove(istream& is, ostream& os) {
    while (true) {
        os << "How many would you like to take?" << endl;
        os << "Input your amount: ";
        int nTaken;
        is >> nTaken;
        int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
        if (nTaken > 0 && nTaken <= limit)
            return nTaken;
        else {
            os << "Illegal amount. You can only take between " << endl;
            os << "1 and " << MAX_MOVE << " coins. Try again.";
        }
    }
}

void SimpleNim::announceResult(ostream& os) {
    if (nCoins == 0)
        os << "You took last coin. You lose." << endl;
    else {
        os << "There is only one coin left. " << endl;
        if (whoseTurn == HUMAN)
            os << "I win." << endl;
        else
            os << "I lose." << endl;
    }
}

