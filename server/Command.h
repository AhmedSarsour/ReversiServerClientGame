/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H
#include<vector>
#include <string>
using namespace std;
class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual~Command() {}
};
#endif //REVERSI_COMMAND_H
