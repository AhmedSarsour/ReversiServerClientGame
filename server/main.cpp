#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main() {
    string line;
    int numberLine = 0;
    string ip;
    int port;
    ifstream myfile("ssettings.txt");
    // The first line is the port
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (numberLine == 0) {
                // Converting the port to number.
                port = atoi(line.c_str());
            }
            //cout << line << '\n';
            numberLine++;
        }
        // Closing the file.
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }
    //creating the server.
    Server server(port);
    try {
        //calling the start of the server.
        server.start();
        string str;
        //while the option isn't "exit" then retyping the input.
        do {
            cin >> str;
            if (str == "exit") {
                server.stop();
            } else {
                cout<< "invalid option!" << endl;
            }
        } while (str != "exit");
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);

    }
}
