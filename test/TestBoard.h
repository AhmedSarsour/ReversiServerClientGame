#ifndef TESTBOARD_H
#define TESTBOARD_H
#include "gtest/gtest.h"
#include "../src/ConsoleBoard.h"
class TestBoard: public testing::Test {
protected:
    int row;
    int col;
    HumanPlayer * firstPlayer;
    AiPlayer *secondPlayer;
    //creating the board.
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
TEST_F(TestBoard,TESTBOUNDARIES) {
    EXPECT_EQ(board->getRows(),row);
    EXPECT_EQ(board->getRows(),col);
    EXPECT_EQ(board->getFirstPlayer()->getName(), "X");
    EXPECT_EQ(board->getSecondPlayer()->getName(), "O");

}

#endif //REVERSITESTS_TESTBOARD_H
