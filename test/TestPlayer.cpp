/*
 * student 1: ahmed sarsour. 315397059
 * student 2: Eliad Arzuan 206482622
 */
#include "gtest/gtest.h"
#include "TestPlayer.h"
#include "../src/BasicRules.h"
#include "../src/ConsoleBoard.h"
#include "../src/AiPlayer.h"
#include "../src/HumanPlayer.h"
#include "../src/PointsList.h"
#include "../src/Point.h"
//Tests the play turn function.
TEST_F(TestPlayer, TestPlayTurn) {
    //Setting a board and players.
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
//Tests if the getName function work.
TEST_F(TestPlayer, TestGetName) {
    //Creates function for example.
    HumanPlayer firstPlayer = HumanPlayer("X");
    AiPlayer secondPlayer = AiPlayer("O");
    EXPECT_EQ(firstPlayer.getName(), "X");
    EXPECT_EQ(secondPlayer.getName(), "O");
    EXPECT_NE(firstPlayer.getName(), "O");
    EXPECT_NE(secondPlayer.getName(), "X");
}
