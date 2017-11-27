#ifndef TESTBOARD_H
#define TESTBOARD_H
#include "gtest/gtest.h"
#include "../src/ConsoleBoard.h"
#include "../src/BasicRules.h"

class TestBoard: public testing::Test {
protected:
<<<<<<< HEAD
    int row;
    int col;
    HumanPlayer * firstPlayer;
    AiPlayer *secondPlayer;
    //creating the board.
    ConsoleBoard * board;
=======
     int row;
     int col;
      HumanPlayer * firstPlayer;
      AiPlayer *secondPlayer;
    //	//creating the board.
     ConsoleBoard * board; BasicRules * rules;
>>>>>>> cd2f83ce396cc5b546c92e41bf7171d5e4284d18
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

    ~TestBoard() {
        delete board;
        delete firstPlayer;
        delete secondPlayer;
        delete rules;
    }
};
<<<<<<< HEAD
TEST_F(TestBoard,TESTBOUNDARIES) {
    EXPECT_EQ(board->getRows(),row);
    EXPECT_EQ(board->getRows(),col);
    EXPECT_EQ(board->getFirstPlayer()->getName(), "X");
    EXPECT_EQ(board->getSecondPlayer()->getName(), "O");
=======
>>>>>>> cd2f83ce396cc5b546c92e41bf7171d5e4284d18

}

#endif //REVERSITESTS_TESTBOARD_H
