//
// Created by coraledge on 27/11/17.
//

#include "TestRules.h"
#include "gtest/gtest.h"
#include "../src/AiPlayer.h"
#include "../src/HumanPlayer.h"
#include "../src/BasicRules.h"
#include "../src/ConsoleBoard.h"

TEST_F(TestRules, CheckCells) {
    int row = 8, col = 8;
    HumanPlayer firstPlayer = HumanPlayer("X");
    AiPlayer secondPlayer = AiPlayer("O");
    BasicRules rules = BasicRules(row,col);
    ConsoleBoard theGameBoard  = ConsoleBoard(row, col, &firstPlayer, &secondPlayer);
    theGameBoard.buildTheBoard(&rules);
    int ** ourBoard = theGameBoard.getReversi();
    //Player 1 == X player 2 == Y
    EXPECT_EQ(ourBoard[4][4],2);
    EXPECT_EQ(ourBoard[3][4],1);
    EXPECT_EQ(ourBoard[3][3],2);
    EXPECT_EQ(ourBoard[4][3],1);
    //Checks if all the other cells in the board are 0.
    for (int i = 0; i < theGameBoard.getRows(); i++) {
        //Not player 1 or 2.
        if (i != 4 && i != 3) {
            for (int j = 0; j < theGameBoard.getCols(); j++) {
                if (j != 4 && j != 3) { //Not player 1 or 2
                    EXPECT_EQ(ourBoard[i][j], 0);
                }
            }
        }
    }
}

TEST_F(TestRules, TestConvertPieces) {
    int row = 8, col = 8;
    HumanPlayer firstPlayer = HumanPlayer("X");
    AiPlayer secondPlayer = AiPlayer("O");
    BasicRules rules = BasicRules(row,col);
    ConsoleBoard theGameBoard  = ConsoleBoard(row, col, &firstPlayer, &secondPlayer);
    theGameBoard.buildTheBoard(&rules);
    int** reversi = theGameBoard.getReversi();
    //X has 4 options, (6,5),(4,3),(3,4),(5,6)
    int choiceRow = 6;
    int choiceCol = 5;
    int xTurn = 1;
    //we check a piece between (choicePoint n other X) n check if it converted.
    EXPECT_EQ(reversi[4][4], 2);
    theGameBoard.getReversi()[choiceRow - 1][choiceCol - 1] = 1;
    rules.convertPieces(reversi, xTurn, choiceRow, choiceCol);
    //it should convert then we check "not equal".
    EXPECT_NE(reversi[4][4], 2);
}

TEST_F(TestRules, TestCheckPoints) {
    int row = 8, col = 8;
    HumanPlayer firstPlayer = HumanPlayer("X");
    AiPlayer secondPlayer = AiPlayer("O");
    BasicRules rules = BasicRules(row,col);
    ConsoleBoard theGameBoard  = ConsoleBoard(row, col, &firstPlayer, &secondPlayer);
    theGameBoard.buildTheBoard(&rules);
    int** reversi = theGameBoard.getReversi();
    list<Point> list = rules.checkPoints(reversi, 1) ;
    EXPECT_TRUE(!list.empty());
}