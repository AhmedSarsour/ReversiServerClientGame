/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H
#include "Command.h"
#include <iostream>
/**
 * ListCommand.
 * This command send to the client list of avaliable games that he can join.
 */
class ListCommand: public Command {
public:
    /**
     * Excecute.
     * @param args the arguments to the function to do.
     * @param gameCollection a games collection.
     * @param clientAddresses array of 2 clients addresses (first on 0 second on 1)
     * @param clientAddressLens array of 2 clients lens (first on 0 second on 1)
     * @param serverSocket the socket to the server
     */
    void execute(vector<string> args, GameCollection &gameCollection){
        //  Getting the available games.
        vector<string> available = gameCollection.getAvailableGames();
        for (int i = 0; i < available.size(); i++) {
            cout << "GameInfo: " << available[i] << endl;
        }

    }
};

#endif //LISTCOMMAND_H
