/*
 * student 1: ahmed sarsour. 315397059
 * student 2: Eliad Arzuan 206482622
 */

#ifndef TESTBOARD_H
#define TESTBOARD_H
#include "gtest/gtest.h"
#include "../src/ConsoleBoard.h"
#include "../src/BasicRules.h"
/*
 * TestBoard.
 * Class that tests the board functions.
 */
class TestBoard: public testing::Test {
protected:
     int row;
     int col;
      HumanPlayer * firstPlayer;
      AiPlayer *secondPlayer;
     ConsoleBoard * board;
     BasicRules * rules;
public:
    /**
     * The constructor.
     * Set a board with players that we will check the board functions on it.
     */
    TestBoard() {
        //Set the board margins.
        row = 8;
        col = 8;
        //Creates two players for instance.
        firstPlayer = new HumanPlayer("X");
        secondPlayer = new AiPlayer("O");
        //Creating the board.
        board = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
        rules = new BasicRules(row,col);
        //Build the board by the rules.
        board->buildTheBoard(rules);
    }
/**
 * The destructor of our class because we allocated memmory.
 */
    ~TestBoard() {
        delete board;
        delete firstPlayer;
        delete secondPlayer;
        delete rules;
    }

};


#endif //TESTBOARD_H
