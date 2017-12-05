//
// Created by eliad1998 on 05/12/17.
//

#ifndef SERVER_H
#define SERVER_H

class Server {
public:
    /**
     * The constructor of our class
     * @param port
     */
    Server(int port);
    /**
     * Start.
     * Starts the server.
     */
    void start();
    /**
     * Stop.
     * Stops the server.
     */
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    /**
     * HandleClients.
     * Handle with the both clients.
     * @param clientSocket1 The socket of the first player.
     * @param clientSocket2 The socket of the second player.
     */
    void handleClients(int client1Socket, int clientSocket2);
    // Send a message just for the client waiting for it.
    /**
     * SendActivation
     * Sends a message to the player by the socket of the player. The player on the client side will wait untill
     * he got a message (by the function read).
     * @param socket the socket of the specific player.
     */
    void sendActivation(int socket);
};


#endif //SERVER_H
