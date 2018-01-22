/*
 * server
 *      student 1: ahmed sarsour 315397059
 *      student 2: Eliad Arzuan  206482622
 */
#include "Server.h"
#define MAX_CONNECTED_CLIENTS 500
using namespace std;
#define THREADS_NUM 5
static void* acceptClients(void * arguments);
CommandsManager cm = CommandsManager();
Server::Server(int port) :
        port(port), serverSocket(0), threadPool(new ThreadPool(THREADS_NUM)) {
    cout << "server" << endl;
}

typedef struct {
    long socket;
    Server * server;
} ExArgs;

static void* clientHandle(void * arguments);
//Starts the server
void Server::start() {
//    cout <<  "my socket is " << serverSocket<<endl;
//    if (serverSocket > 0) {
//        close(serverSocket);
//    }
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    // Checks if the binding is ok
    if (bind(serverSocket, (struct sockaddr *) &serverAddress,
             sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    ExArgs * exArgs = new ExArgs;
    exArgs->socket = serverSocket;
    exArgs->server = this;
    pthread_create(&serverThreadId, NULL, acceptClients, (void*) exArgs);

}

void* acceptClients(void * arguments) {
    ExArgs* exArgs = (ExArgs*)arguments;
    long serverSocket = exArgs->socket;
    Server * server = exArgs->server;
    // Define the lib socket's structures
    struct sockaddr_in clientAddress; //Fixing error on accept.
    socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);
    while (true) {
        long clientSocket1 = accept(serverSocket,
                                   (struct sockaddr *) &clientAddress, &clientAddressLen);

        exArgs->socket = clientSocket1;
        //Creating threads for commends getting.
        Task * newTask =new Task(&clientHandle,  (void *)clientSocket1);
        server->getThreadPool()->addTask(newTask);

//        pthread_t threadId;
//        pthread_create(&threadId, NULL,&clientHandle, (void *)clientSocket1);
    }
}
void* clientHandle(void * argumnets) {
    long clientSocket1 = (long)argumnets;
    while (true) {
        vector < string > args;
        int size;
        int n;
        n = read(clientSocket1, &size, sizeof(size));
        if (n == -1) {
            throw "Error reading a char from socket";
        }
        cout << "size is : " << size << endl;
        string command = Server::readString(clientSocket1, &size);
        string typeCommand = Server::readString(clientSocket1, &size);
        args.push_back(typeCommand);
        args.push_back(Server::intToString(clientSocket1));

        /***************************************/
        //Getting the argument after the command:
        /****************************************/
        string name = "";
        cout << "Waiting for the players connections..." << endl;
        cout << "I pass the vector " << args[1] << endl;
        // 0 - chose list_games wrong with the command so we will continue.
        // Any other value is ok so we break.
        if (cm.executeCommand(command, args) != 0) {
            break;
        }
    }
}

string Server::readString(int socket, int* sizeOf) {
    int size = *sizeOf;
    int clientSocket1 = socket;
    int n;
    char c2;
    char c[1];
    //com is the string that holds the command.
    string com = "";
    //in this do-while, we read the command
    do {
        if (size > 0) {
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
        //i did "&& size > 0" because it is needed for the "list_games" command.
    } while (c[0] != ' ' && size > 0);
    cout << "command is : " << com << endl;
    //changing the original value of the size of the string.
    *sizeOf = size;
    return com;

}
//Stops the server
void Server::stop() {

    cm.closeAllGames();
    pthread_cancel (serverThreadId);
    close (serverSocket);
//    delete this->getThreadPool();
    cout << "Server stopped" << endl;
}
//Getting the server socket.
int Server::getSocket() {
    return this->serverSocket;
}

//Helping converting int to string.
string Server::intToStringHelper(int x, string str) {
    if (x == 0) {
        return str;
    }
    char ch = (char) ((x % 10 + '0'));
    // Put the char in the end because moves by the digits.
    return intToStringHelper(x / 10, str) + ch;
}

string Server::intToString(int num) {
    return intToStringHelper(num, "");
}