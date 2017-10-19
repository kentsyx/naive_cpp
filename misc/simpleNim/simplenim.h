/* File: simplenim.h
 * -----------------
 * This file exports the interface for a kind of game called Nim.
 */

#include <iostream>
#include <string>
#include "error.h"
#include "strlib.h"

extern const int N_COINS;
extern const int MAX_MOVE;
extern const int NO_GOOD_MOVE;

enum Player {HUMAN, COMPUTER};

extern const Player STARTING_PlAYER;

Player opponent(Player);

class SimpleNim {
public:
    void printInstructions(std::ostream&);
    void play(std::ostream&);

private:
    int getComputerMove();
    int findGoodMove(int);
    bool isBadPosition(int);
    int getUserMove(std::istream&, std::ostream&);
    void announceResult(std::ostream&);
    /* instance variables */
    int nCoins;
    Player whoseTurn;

};
