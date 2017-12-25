/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#ifndef REVERSI_CLOSECOMMAND_H
#define REVERSI_CLOSECOMMAND_H
#include "Command.h"
#include <iostream>
class CloseCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        //i think we need a vector of games(lets say named gamesVec), we call the game with
        //gamesVec.getGame(args[0])->deleteBoard();
        /*
        theGameBoard->deleteBoard();
        delete theGameBoard;
        delete firstPlayer;
        delete secondPlayer;
        delete rules;
        */
    }
};
#endif //REVERSI_CLOSECOMMAND_H
