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
        int n;
        int clientSocket1 = atoi(args[1].c_str());
        cout << "The socket is :" << clientSocket1;
        cout << endl;
        if (!available.empty()) {
            for (int i = 0; i < available.size(); i++) {
                char comma = ',';
                string s = available[i];
                //i think we need to specify the size of the string, sizeof doesn't know..........
                char nameChar;
                for (int j = 0; j < s.size(); j++) {
                    nameChar = s.at(j);
                    n = write(clientSocket1, &nameChar, sizeof(nameChar));
                    if (n == -1) {
                        throw "Error writing a game's name into socket";
                    }
                }
                if (i != available.size() - 1) {
                    n = write(clientSocket1, &comma, sizeof(comma));
                    if (n == -1) {
                        throw "Error writing a comma into socket";
                    }
                }
            }
            for (int i = 0; i < available.size(); i++) {
                cout << "GameInfo: " << available[i] << endl;
            }
        } else {
            cout << "no games" << endl;
        }
        //we determine the end of the string by reading until reaching # in socket.
        char end = '#';
        n = write(clientSocket1, &end, sizeof(end));
        if (n == -1) {
            throw "Error reading a char from socket";
        }

    }
};

#endif //LISTCOMMAND_H
