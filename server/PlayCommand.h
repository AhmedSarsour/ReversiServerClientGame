/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef REVERSI_PLAYCOMMAND_H
#define REVERSI_PLAYCOMMAND_H
#include "Command.h"
#include <iostream>
class PlayCommand: public Command {
public:
    //i think: we get a vector of the moves, first we get <x> then we get <y>.
    void execute(vector<string> args) {
        int moveRow = args[0].at(1);//<x> == first "<", 2nd is "x", 3rd is ">", so we do string.at(1).
        int moveCol = args[1].at(1);
        //now we make something like == client.writeMove(moveRow, MoveCol);
    }
};

#endif //REVERSI_PLAYCOMMAND_H
