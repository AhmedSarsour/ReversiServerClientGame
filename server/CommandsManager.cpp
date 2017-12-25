/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartCommand();
    commandsMap["list_games"] = new ListCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["play"] = new PlayCommand();
    commandsMap["close"] = new CloseCommand();
}
void CommandsManager::executeCommand(string
                                     command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}

