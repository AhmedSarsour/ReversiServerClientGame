/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef REVERSI_COMMANDSMANAGER_H
#define REVERSI_COMMANDSMANAGER_H
#include <map>
#include "Command.h"
class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command,
                        vector<string> args);
private:
    map<string, Command *> commandsMap;
};
#endif //REVERSI_COMMANDSMANAGER_H
