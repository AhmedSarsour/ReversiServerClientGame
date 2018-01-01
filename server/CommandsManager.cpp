/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#include "CommandsManager.h"
//Constructor
CommandsManager::CommandsManager() {
    // Initializing the map.
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"] = new ListCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["close"] = new CloseCommand();
    // Initializing the game collection.
    this->gameCollection = GameCollection();

}
// Excecutes a command.
int CommandsManager::executeCommand(string command, vector<string> args) {
    // Get a command from the map.
    Command *commandObj = commandsMap[command];
    //Doing the command
    return commandObj->execute(args, &gameCollection);
}
//Destructor.
CommandsManager::~CommandsManager() {
    // Deleting the map.
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}