#include "TaskContainer.h"

TaskContainer::TaskContainer()
{
}

TaskContainer::~TaskContainer()
{
}

void TaskContainer::Push(Task* t)
{
    taskContainer.push(t);
}

Task* TaskContainer::Top()
{
    return taskContainer.top();
}

void TaskContainer::Pop()
{
    taskContainer.pop();
}

std::priority_queue<Task*>::size_type TaskContainer::Size()
{
    return taskContainer.size();
}
