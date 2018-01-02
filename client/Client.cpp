/*
 *      student 1: ahmed sarsour 315397059
 *      student 2: Eliad Arzuan  206482622
 */
#include"Client.h"
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include "Point.h"
using namespace std;
Client::Client(const char *serverIP, int serverPort) :
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    cout << "Client" << endl;
}

void Client::connectToServer() {
// Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof(address), AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    // htons converts values between host and network byteorders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr*) &serverAddress,
                sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
}
int Client::wait() {
    int x;
    int n = read(clientSocket, &x, sizeof(x));
    // Check if there is a problem reading from the socket.
    checkProblem(n);
    return x;
}

Point Client::getMove() {
    int arg1, arg2;
    int n = read(clientSocket, &arg1, sizeof(arg1));
    checkProblem(n);
    n = read(clientSocket, &arg2, sizeof(arg2));
    checkProblem(n);
    // Return point from the both arguments.
    return Point(arg1, arg2);

}
//Send move to the server
Point Client::sendMove(int x, int y) {
    // Write the point arguments to the socket
    int n = write(clientSocket, &x, sizeof(x));
    // Checking if there is problem writing to the socket.

    checkProblem(n);
    n = write(clientSocket, &y, sizeof(y));
    // Checking if there is problem writing to the socket.
    checkProblem(n);
    return Point(x, y);
}

/**
 * writeToSocket: it gets a string, writes it into the client's socket.
 * @param command
 */
void Client::writeToSocket(string command) {
    //getting the size of the input string.
    int size = command.size();
    //writing the size of the command at the beginning of the socket.
    int n = write(clientSocket, &size, sizeof(size));
    checkProblem(n);

    if (n == 0) {
        throw "Sorry the server was closed";
    }
    //writing the command "char by char" in the socket.
    char c;
    for (int i = 0; i < command.size(); i++) {
        c = command.at(i);
        n = write(clientSocket, &c, sizeof(c));
        checkProblem(n);
        if (n == 0) {
            throw "Sorry the server was closed";
        }
    }
}
// Reading our operation
int Client::readOperation() {
    char c;
    int n;
    //reading the symbol we got from the server.
    n = read(clientSocket, &c, sizeof(c));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    //in case the symbol was '-' then printing:
    if (c == '-') {
        cout << "there is an already existing game with such name!" << endl;
        cout << "please pick another one." << endl;
        return -1;
    //in case the symbol was '+' then printing the following:
    } else if (c == '+') {
        cout << "there is no existing game with the name you entered!" << endl;
        return -1;
        // List games- we are going to read more strings.
    } else if (c == 'e') {
        readListGames();
        return 2;
    }
    //read successfully.
    return 1;
}

void Client::readListGames() {
    int n;
    int size;
    //we read the size of the given string in the socket.
    n = read(clientSocket, &size, sizeof(size));
    char c2;
    char c[1];
    //com is the string that holds the command.
    string com = "";
    //in this do-while, we read the command
    do {
        if (size > 0) {
            //reading the characters. saving them in c2.
            n = read(clientSocket, &c2, sizeof(c2));
            size--;
            if (n == -1) {
                throw "Error reading a char from socket";
            }
            //saving the char in c[0] in order to do append(append doesn't accept char, but char*).
            c[0] = c2;
            com.append(c);
        }
        //i did here && size > 0 because it is needed for the "list_games" command.
    } while (size > 0);
    cout << "Games : " << com << endl;
}


void Client::checkProblem(int n) {
    if (n == -1) {
        // Closing the client socket.
        // close(clientSocket);
        throw "Error writing to socket probebly the server was closed ";
    }

    if (n == 0) {
        // Closing the client socket.
        //  close(clientSocket);
        throw "Client disconnected or the server was closed";
    }
}