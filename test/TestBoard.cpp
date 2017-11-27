//
// Created by eliad1998 on 27/11/17.
//
#include "TestBoard.h"

TEST_F(TestBoard,CheckMargins) {
    //Check the rows of the board.
    EXPECT_EQ(board->getRows(), 8);
    //Chceck the cols of the board.
    EXPECT_EQ(board->getCols(), 8);

}
//Test the board in it's start position
TEST_F(TestBoard, CheckCells) {
    int ** ourBoard = board->getReversi();
    //Player 1-X player 2-Y
    EXPECT_EQ(ourBoard[4][4],2);
    EXPECT_EQ(ourBoard[3][4],1);
    EXPECT_EQ(ourBoard[3][3],2);
    EXPECT_EQ(ourBoard[4][3],1);

    //Checks if all the other cells in the board are 0.
    for (int i = 0; i < board->getRows(); i++) {
        //Not player 1 or 2.
        if (i != 4 && i != 3) {
            for (int j = 0; j < board->getCols(); j++) {
                if (j != 4 && j != 3) { //Not player 1 or 2
                    EXPECT_EQ(ourBoard[i][j], 0);
                }
            }
        }
    }
}

TEST_F(TestBoard, CheckCurrentTurn) {
    //The first is 0 x starts from 0 than 1 is O
    Player * player = board->getCurrentTurnPlayer(1);

    EXPECT_EQ(player->getName(),"O");

    player = board->getCurrentTurnPlayer(0);
    EXPECT_EQ(player->getName(),"X");
}

