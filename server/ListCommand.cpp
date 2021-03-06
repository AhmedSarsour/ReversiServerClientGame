/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#include "ListCommand.h"
pthread_mutex_t listMutex;

int ListCommand::execute(vector<string> args, GameCollection *gameCollection) {
    //  Getting the available games.
    //Locking - game collection is collaberated memmory.
    pthread_mutex_lock(&listMutex);
    vector < string > available = gameCollection->getAvailableGames();
    pthread_mutex_unlock(&listMutex); //Unlocking
    int n;
    int clientSocket1 = atoi(args[1].c_str());
    //first read e than the game names.
    //e - symbolized we are going to read more strings.
    char end = 'e';
    n = write(clientSocket1, &end, sizeof(end));
    if (n == -1) {
        throw "Error reading a char from socket";
    }
    int size; // Size of string to read.
    //First sending the size of the list_games
    string send = ""; //send variable holds the whole information about the games.
    if (available.empty()) {
        cout << "no games" << endl;
        send = "No games";
    } else {
        send.append("The games are: \n");
        for (int i = 0; i < available.size(); i++) {
            char comma = ',';
            //printing the gameInfo into server.
            cout << "GameInfo:" << available[i] << endl;
            //appending the gamename into
            send.append("Game: " + available[i]);
            if (i != available.size() - 1) {
                send.append("\n");        // "\n";
            }
        }
    }
    size = (int) send.size();
    //writing the size of the command at the beginning of the socket.
    n = write(clientSocket1, &size, sizeof(size));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    //writing the command "char by char" in the socket.
    char c;
    for (int i = 0; i < size; i++) {
        c = send.at(i);
        n = write(clientSocket1, &c, sizeof(c));
        if (n == -1) {
            throw "Error writing arg1 to socket";
        }
    }
    return 0;

}

