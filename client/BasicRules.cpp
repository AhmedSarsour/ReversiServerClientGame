/*
 * BasicRules.cpp
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */

#include "BasicRules.h"

#include "Point.h"
#include "PointsList.h"
using namespace std;
/**
 * BasicRules constructior.
 * @param: rows;
 * @param: cols
 */
BasicRules::BasicRules(int rows, int cols) {
    this->row = rows;
    this->col = cols;
}
/**
 * buildBoard function.
 * @param: reversi.
 * function: it builds the initial board according the basic rules
 * of the game.
 */
void BasicRules::buildBoard(int** reversi) {
    int i = 0, j = 0;
    for (i = 0; i < this->row; i++) {
        for (j = 0; j < this->col; j++) {
            reversi[i][j] = 0;
        }
    }
    /*
     occupying the middle spots.
     1 == X, 2 == O, else (most likely 0) == " ";
     */
    reversi[this->row / 2 - 1][this->col / 2 - 1] = 2;
    reversi[this->row / 2][this->col / 2] = 2;
    reversi[this->row / 2 - 1][this->col / 2] = 1;
    reversi[this->row / 2][this->col / 2 - 1] = 1;
}
/**
 * checkPoints function.
 * @param reversi.
 * @param playerXorO.
 * @param choiceList.
 * @return list<Point>.
 * function: it returns a list of a playable choices, list of Points.
 */
list<Point> BasicRules::checkPoints(int** reversi, int playerXorO) {
    list<Point> choicesList;
    int i, j, theRow, theCol;
    for (i = 0; i < this->row; i++) {
        for (j = 0; j < this->col; j++) {
            //if value is O or X.
            if (reversi[i][j] == playerXorO) {
                theRow = i;
                theCol = j;
                // checking the up side of the player's piece.
                if (theRow != 0) {
                    do {
                        theRow--;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theRow > 0);
                    // adding a Point if it is a available.
                    if (theRow >= 0 && theRow != i - 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                theRow = i;
                theCol = j;
                //checking the downside of the player's piece.
                if (theRow != this->row - 1) {
                    do {
                        theRow++;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theRow < this->row - 1);
                    if (theRow < this->row && theRow != i + 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                theRow = i;
                theCol = j;
                //checking the left side of the player's piece.
                if (theCol != 0) {
                    do {
                        theCol--;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theCol > 0);
                    if (theCol >= 0 && theCol != j - 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                theRow = i;
                theCol = j;
                //checking the write side of the player's piece.
                if (theCol != this->col - 1) {
                    do {
                        theCol++;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theCol < this->col - 1);
                    if (theCol < this->col && theCol != j + 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                //now, checking the diagonal sides of the player's piece.
                theRow = i;
                theCol = j;
                if (theCol != 0 && theRow != 0) {
                    do {
                        theCol--;
                        theRow--;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theCol > 0 && theRow > 0);
                    if (theCol >= 0 && theCol != j - 1 && theRow >= 0
                        && theRow != i - 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                theRow = i;
                theCol = j;
                if (theRow != this->row - 1 && theCol != this->col - 1) {
                    do {
                        theCol++;
                        theRow++;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theCol < this->col - 1 && theRow < this->row - 1);
                    if (theCol < this->col && theCol != j + 1
                        && theRow < this->row && theRow != i + 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                theRow = i;
                theCol = j;
                if (theCol != 0 && theRow != this->row - 1) {
                    do {
                        theCol--;
                        theRow++;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theCol > 0 && theRow < this->row - 1);
                    if (theCol >= 0 && theCol != j - 1 && theRow < this->row
                        && theRow != i + 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
                theRow = i;
                theCol = j;
                if (theCol != this->col - 1 && theRow != 0) {
                    do {
                        theCol++;
                        theRow--;
                    } while (reversi[theRow][theCol] == 3 - playerXorO
                             && theCol < this->col - 1 && theRow > 0);
                    if (theCol < this->col && theCol != j + 1 && theRow >= 0
                        && theRow != i - 1
                        && reversi[theRow][theCol] == 0) {
                        choicesList.push_back(Point(theRow + 1, theCol + 1));
                    }
                }
            }
        }
    }
    return choicesList;
}
/**
 * convertPieces function.
 * @param reversi.
 * @param playerXorO.
 * @param choiceRow.
 * @param ChoiceCol.
 * function: it gets the Point that the player chose, and then converts
 * the nearby pieces of the game according the basic rules of the game.
 */
void BasicRules::convertPieces(int** reversi, int playerXorO, int choiceRow,
                               int choiceCol) {
    int theCol, theRow;
    bool goforit = false;
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    //if goforit goes true, then some pieces are gonna convert.
    goforit = false;
    if (choiceRow != 1) {
        do {
            theRow--;
            //stop condition.
            if (reversi[theRow][theCol] == playerXorO && theRow != choiceRow - 2) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO && theRow > 0);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        //converting the pieces between the picked choice and other piece.
        do {
            theRow--;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            //stop condition so we don't go outside of the array borders.
            if (theRow - 1 < 0) {
                break;
            }
        } while (reversi[theRow - 1][theCol] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceRow != this->row) {
        do {
            theRow++;
            //Stop condition.
            if (reversi[theRow][theCol] == playerXorO && theRow != choiceRow ) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO
                 && theRow < this->row - 1);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theRow++;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theRow + 1 >= this->row) {
                break;
            }
        } while (reversi[theRow + 1][theCol] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceCol != 1) {
        do {
            theCol--;
            if (reversi[theRow][theCol] == playerXorO && theCol != choiceCol - 2) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO && theCol > 0);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theCol--;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theCol - 1 < 0) {
                break;
            }
        } while (reversi[theRow][theCol - 1] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceCol != this->col) {
        do {
            theCol++;
            if (reversi[theRow][theCol] == playerXorO && theCol != choiceCol) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO
                 && theCol < this->col - 1);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theCol++;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theCol + 1 >= this->col) {
                break;
            }
        } while (reversi[theRow][theCol + 1] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceRow != 1 && choiceCol != 1) {
        do {
            theRow--;
            theCol--;
            if (reversi[theRow][theCol] == playerXorO && theRow != choiceRow - 2) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO && theRow > 0
                 && theCol > 0);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theRow--;
            theCol--;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theRow - 1 < 0 || theCol - 1 < 0) {
                break;
            }
        } while (reversi[theRow - 1][theCol - 1] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceRow != this->row && choiceCol != this->col) {
        do {
            theRow++;
            theCol++;
            if (reversi[theRow][theCol] == playerXorO && theRow != choiceRow) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO
                 && theRow < this->row - 1 && theCol < this->col - 1);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theRow++;
            theCol++;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theRow + 1 >= this->row || theCol + 1 >= this->col) {
                break;
            }
        } while (reversi[theRow + 1][theCol + 1] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceRow != this->row && choiceCol != 1) {
        do {
            theRow++;
            theCol--;
            if (reversi[theRow][theCol] == playerXorO && theRow != choiceRow) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO
                 && theRow < this->row - 1 && theCol > 0);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theRow++;
            theCol--;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theRow + 1 >= this->row || theCol - 1 < 0) {
                break;
            }
        } while (reversi[theRow + 1][theCol - 1] == 3 - playerXorO);
    }
    theRow = choiceRow - 1;
    theCol = choiceCol - 1;
    goforit = false;
    if (choiceRow != 1 && choiceCol != this->col) {
        do {
            theRow--;
            theCol++;
            if (reversi[theRow][theCol] == playerXorO && theRow != choiceRow - 2) {
                goforit = true;
                break;
            }
        } while (reversi[theRow][theCol] == 3 - playerXorO && theRow > 0
                 && theCol < this->col - 1);
        theRow = choiceRow - 1;
        theCol = choiceCol - 1;
    }
    if (goforit) {
        do {
            theRow--;
            theCol++;
            if (reversi[theRow][theCol] == 3 - playerXorO) {
                reversi[theRow][theCol] = playerXorO;
            }
            if (theRow - 1 < 0 || theCol + 1 >= this->col) {
                break;
            }
        } while (reversi[theRow - 1][theCol + 1] == 3 - playerXorO);
    }
}
