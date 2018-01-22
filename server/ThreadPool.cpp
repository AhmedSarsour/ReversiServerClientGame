//
// Created by coraledge on 20/01/18.
//

#include "ThreadPool.h"
#include <unistd.h>
ThreadPool::ThreadPool(int threadsNum) :
        stopped(false) {
    threads = new pthread_t[threadsNum];
    for (int i = 0; i < threadsNum; i++) {
        //Creates our threades.
        pthread_create(threads + i, NULL, execute,
                       this);
    }
    pthread_mutex_init(&lock, NULL);
}
void* ThreadPool::execute(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    pool->executeTasks();
}
void ThreadPool::addTask(Task *task) {
    tasksQueue.push(task);
}
void ThreadPool::executeTasks() {
    while (!stopped) {
        //I do the locks in the commands.
        pthread_mutex_lock(&lock);
        if (!tasksQueue.empty()) {
            Task* task = tasksQueue.front();
            tasksQueue.pop();
            //I do the locks in the commands.
             pthread_mutex_unlock(&lock);
            task->execute();
           // delete task;
        }
        else {
            //I do the locks in the commands.

            pthread_mutex_unlock(&lock);
            usleep(1);
        }
    }
}
void ThreadPool::terminate() {
    pthread_mutex_destroy(&lock);

    stopped = true;
}
ThreadPool::~ThreadPool() {
    delete[] threads;
}