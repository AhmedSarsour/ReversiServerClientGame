#include "Server.h"


using namespace std;
#define MAX_CONNECTED_CLIENTS 2 //2 Players
Server::Server(int port): port(port), serverSocket(0) {
    cout << "server" << endl;
}
void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    // Checks if the binding is ok
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the lib socket's structures
    struct sockaddr_in clientAddress; //Fixing error on accept.
    socklen_t clientAddressLen =  sizeof((struct sockaddr*) &clientAddress);

    struct sockaddr_in client2Address;//Fixing error on accept.
    socklen_t client2AddressLen = sizeof((struct sockaddr*) &client2Address);

    // The game itself
    int clientSocket1 = accept(serverSocket, (struct
            sockaddr *) &clientAddress, &clientAddressLen);
    cout << "Socket is :"<< clientSocket1<<endl;

    clientHandle(clientSocket1);
   // close(clientSocket1);
    while (true) {
        cout << "Waiting for the players connections..." << endl;
        CommandsManager cm = CommandsManager();
        struct sockaddr_in clientAddresses[] = {clientAddress, client2Address}; //Fixing error on accept.
        //socklen_t clientAddressLens[] =  {clientAddressLen, client2AddressLen};
        vector <string> args;
        args.push_back("a");
        args.push_back(clientSocket1 + "");
        cm.executeCommand("start", args);
        cm.executeCommand("list_games", args);
        break;
     //   cm.executeCommand("join", args);
    }
}

void Server::clientHandle(int clientSocket1) {
    //this vector is just for checking...
    vector <string> canPlay;
    canPlay.push_back("noob");
    canPlay.push_back("noober");
    canPlay.push_back("noobie");
    canPlay.push_back("noobieTazz");
    while (true) {
        int size;
        int n;
        //we read the size of the given string in the socket.
        n = read(clientSocket1, &size, sizeof(size));
        if (n == -1) {
            throw "Error reading a char from socket";
        }
        cout << "size is : " << size << endl;
        char c2;
        char c[1];
        //com is the string that holds the command.
        string com = "";
        //in this do-while, we read the command
        do {
            if(size > 0) {
                //reading the characters. saving them in c2.
                n = read(clientSocket1, &c2, sizeof(c2));
                size--;
                if (n == -1) {
                    throw "Error reading a char from socket";
                }
                //saving the char in c[0] in order to do append(append doesn't accept char, but char*).
                c[0] = c2;
                if (c[0] != ' ') {
                    com.append(c);
                }
            }
            //i did here && size > 0 because it is needed for the "list_games" command.
        }while(c[0] != ' ' && size > 0);
        cout << "command is : " << com << endl;
        break;
        //now checking the commands.
//
    }
}
