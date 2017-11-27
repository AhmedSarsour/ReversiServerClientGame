//
// Created by eliad1998 on 27/11/17.
//

#ifndef TESTBOARD_H
#define TESTBOARD_H
#include "gtest/gtest.h"
#include "../src/ConsoleBoard.h"
class TestBoard: public testing::Test {
protected :
     int row;
     int col;
      HumanPlayer * firstPlayer;
      AiPlayer *secondPlayer;
    //	//creating the board.
     ConsoleBoard * board;
public:
    TestBoard() {
        row = 8;
        col = 8;
        firstPlayer = new HumanPlayer("X");
        secondPlayer = new AiPlayer("O");
        board = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
    }

};
//Put tests here
TEST_F(TestBoard,TESTBOUNDARIES) {
    EXPECT_EQ(board->getRows(),4);
}


#endif //REVERSITESTS_TESTBOARD_H
