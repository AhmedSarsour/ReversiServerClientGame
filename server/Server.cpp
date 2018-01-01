#include "Server.h"


using namespace std;
#define MAX_CONNECTED_CLIENTS 500 //2 Players
Server::Server(int port): port(port), serverSocket(0) {
    cout << "server" << endl;
}
CommandsManager cm = CommandsManager();
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
    vector<pthread_t> threads;
    int index = -1;
    while (true) {
        int clientSocket1 = accept(serverSocket, (struct
                sockaddr *) &clientAddress, &clientAddressLen);
        // The arguments to clientHandle;
        clientHandle(clientSocket1);

      //  pthread_exit(NULL);

       // close(clientSocket1);

    }


    pthread_exit(NULL);
}

void Server::clientHandle(int clientSocket1) {
   while (true) {
        vector<string> args;
   //     Server s = *threadArgs.server;
        // while (true) {
        int size;
        int n;
        //we read the size of the given string in the socket.
        n = read(clientSocket1, &size, sizeof(size));
        if (n == -1) {
            throw "Error reading a char from socket";
        }
        cout << "size is : " << size << endl;
        string command = Server::readString(clientSocket1, &size);
        string typeCommand = Server::readString(clientSocket1, &size);
        args.push_back(typeCommand);
        args.push_back(intToString(clientSocket1));

        /***************************************/
        //Getting the argument after the command:
        /****************************************/
        string name = "";
        cout << "Waiting for the players connections..." << endl;
        cout << "I pass the vector " << args[1] << endl;
        // 0 - chose list_games wrong with the command so we will continue.
        // Any other value is ok so we break.
        if(cm.executeCommand(command, args) != 0){
            break;
        }

       }

    }

string Server::readString(int socket, int* sizeOf) {
    int size = *sizeOf;
    int clientSocket1= socket;
int n;
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
    *sizeOf = size;
    return com;


}


