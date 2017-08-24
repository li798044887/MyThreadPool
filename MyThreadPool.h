#pragma once

#include <thread>
#include <mutex>
#include "Task.hpp"
#include "MyThread.h"
#include "BusyThreadContainer.h"
#include "IdleThreadContainer.h"
#include "TaskContainer.h"

class MyThread;

class MyThreadPool
{
public:
    MyThreadPool(){}
    //构造MyThreadPool,创建包含number个线程的空闲容器
    MyThreadPool(int number);
    ~MyThreadPool();
    //添加一个优先级为priority的任务到任务容器中
    void AddTask(Task *task,int priority);
    //创建n个空闲线程到空闲容器中
    void AddIdleThread(int n);
    //将一个线程从工作容器中删除，并移回空闲容器中
    void RemoveThreadFromBusy(MyThread *myThread);
    //判断是否有空闲线程，如有将任务从任务容器中提出，放入空闲容器中等待执行
    void Start();
    //结束线程池的运行
    void EndMyThreadPool();
private:
    BusyThreadContainer busyThreadContainer;
    IdleThreadContainer idleThreadContainer;
    bool isSurvive;
    TaskContainer taskContainer;
    std::thread threadThis;
    std::mutex busyMutex;
    std::mutex idleMutex;
    std::mutex taskMutex;
    int numberOfThread;
};
