//
// Created by eliad1998 on 27/11/17.
//

#ifndef TESTBOARD_H
#define TESTBOARD_H
#include "gtest/gtest.h"
#include "../src/ConsoleBoard.h"
#include "../src/BasicRules.h"

class TestBoard: public testing::Test {
protected:
     int row;
     int col;
      HumanPlayer * firstPlayer;
      AiPlayer *secondPlayer;
    //	//creating the board.
     ConsoleBoard * board; BasicRules * rules;
public:
    TestBoard() {
        row = 8;
        col = 8;
        firstPlayer = new HumanPlayer("X");
        secondPlayer = new AiPlayer("O");
        board = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
        rules = new BasicRules(row,col);
        //Build the board by the rules.
        board->buildTheBoard(rules);
    }

};


#endif //REVERSITESTS_TESTBOARD_H
