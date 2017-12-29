/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef COMMANDSMANAGER_H
#define COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "GameCollection.h"
#include "StartCommand.h"
#include "ListCommand.h"
#include "JoinCommand.h"
#include "CloseCommand.h"
/**
 * CommandsManager.
 * We are using it command design pattern-  Encapsulate a command as an object, thereby
letting you parameterize clients with different
requests, queue or log requests, and support
undoable operations.
 */
class CommandsManager {
public:
    /**
    * CommandsManager.
    * The constructor of our class.
    * Initialize a commands map and a Game Collection.
     */
    CommandsManager();
    /**
     * The desturcotr of our class.
     */
    ~CommandsManager();
    /**
     * executeCommand.
     * Excecutes a command.
     * @param command the command we want to excecute (start, join,..).
     * @param args arguments to the command (don't know how so pass it in vector).
     * @return 0 - something wrong otherwise - ok
     *
     */
    int executeCommand(string command, vector<string> args);
private:
    map<string, Command *> commandsMap; //Map of commands
    GameCollection gameCollection;      // The collection of the games.
};
#endif //REVERSI_COMMANDSMANAGER_H
