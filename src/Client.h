//
// Created by eliad1998 on 05/12/17.
//

#ifndef CLIENT_H
#define CLIENT_H


#include "Point.h"

class Client {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    Point sendMove(int x, int y);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //REVERSITESTS_CLIENT_H
