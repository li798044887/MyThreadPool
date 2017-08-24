#pragma once

#include <queue>

class Task;

class TaskContainer
{

public:
    TaskContainer();
    ~TaskContainer();
    //将一个任务放入任务容器中
    void Push(Task *t);
    //返回任务容器顶端的任务
    Task* Top();
    //将任务容器顶端的线程弹出
    void Pop();
    //返回任务容器的大小
    std::priority_queue<Task*>::size_type Size();

private:
    std::priority_queue<Task*> taskContainer;
};
