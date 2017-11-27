//
// Created by AhmedSarsour on 27/11/17.
//
#include "gtest/gtest.h"
#include "TestPlayer.h"
#include "../src/BasicRules.h"
#include "../src/ConsoleBoard.h"
#include "../src/AiPlayer.h"
#include "../src/HumanPlayer.h"
#include "../src/PointsList.h"
#include "../src/Point.h"

TEST_F(TestPlayer, TestPlayTurn) {
    int row = 8, col = 8;
    HumanPlayer firstPlayer = HumanPlayer("X");
    AiPlayer secondPlayer = AiPlayer("O");
    BasicRules rules = BasicRules(row, col);
    ConsoleBoard theGameBoard = ConsoleBoard(row, col, &firstPlayer, &secondPlayer);
    theGameBoard.buildTheBoard(&rules);
    //making a list of points for AiPlayer according to initial board state.
    PointsList initBoardAiPlayerChoices;
    initBoardAiPlayerChoices.addPoint(Point(6, 4));
    initBoardAiPlayerChoices.addPoint(Point(4, 6));
    initBoardAiPlayerChoices.addPoint(Point(3, 5));
    initBoardAiPlayerChoices.addPoint(Point(5, 3));
    secondPlayer.setBoardRowNCol(8, 8);
    //checks if the AiPlayer(computer) picks the playable chooice (5,3).
    EXPECT_TRUE(Point(5, 3).equals(secondPlayer.playTurn(theGameBoard.getReversi(), &initBoardAiPlayerChoices, 1)));
}
TEST_F(TestPlayer, TestGetName) {
    HumanPlayer firstPlayer = HumanPlayer("X");
    AiPlayer secondPlayer = AiPlayer("O");
    EXPECT_EQ(firstPlayer.getName(), "X");
    EXPECT_EQ(secondPlayer.getName(), "O");
    EXPECT_NE(firstPlayer.getName(), "O");
    EXPECT_NE(secondPlayer.getName(), "X");
}
