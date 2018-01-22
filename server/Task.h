//
// Created by coraledge on 20/01/18.
//

#ifndef REVERSI_TASK_H
#define REVERSI_TASK_H
class Task {
public:
    /**
     * Constructor of our class.
     * @param func a function
     * @param arg arguments to the functions.
     */
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
    /**
     * excecurte.
     * Excecutes the function.
     */
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    //Pointer to pointer to our function.
    void * (*func)(void *arg);
    void *arg;
};
#endif //REVERSI_TASK_H
