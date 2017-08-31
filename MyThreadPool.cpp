#include <iostream>
#include <thread>
#include "MyThreadPool.h"

MyThreadPool::MyThreadPool(int number)
{
    isSurvive = true;
    numberOfThread = number;
    //创建number个空闲线程放入空闲容器中
    idleThreadContainer.Assign(number,this);
    //创建管理线程threadThis用于进行线程池中线程的调度
    threadThis = std::thread(&MyThreadPool::Start, this);
    threadThis.detach();
}

void MyThreadPool::EndMyThreadPool()
{
    isSurvive = false;
}

void MyThreadPool::AddIdleThread(int n)
{
    idleMutex.lock();
    idleThreadContainer.Assign(n, this);
    numberOfThread += n;
    idleMutex.unlock();
}

void MyThreadPool::Start()
{
    while(true)
    {
        //isSurvive为false则尝试结束跳出循环结束线程池
        if(isSurvive == false)
        {
            busyMutex.lock();
            //判断工作容器中是否有线程
            if(busyThreadContainer.Size()!= 0 )
            {
                busyMutex.unlock();
                continue;
            }
            busyMutex.unlock();
            break;
        }
        
        idleMutex.lock();
        //如果空闲容器中无线程，则直接跳过本次循环体
        if(idleThreadContainer.Size() == 0)
        {
            idleMutex.unlock();
            continue;
        }
        idleMutex.unlock();
        
        taskMutex.lock();
        //如果任务容器中无任务，则直接跳过本次循环体
        if(taskContainer.Size() == 0)
        {
            taskMutex.unlock();
            continue;
        }
        
        //将任务堆顶的任务弹出
        Task *b = taskContainer.Top();
        taskContainer.Pop();
        taskMutex.unlock();
        
        //将弹出的任务与空闲容器的中的一个线程绑定，并将该线程弹出
        idleMutex.lock();
        MyThread *myThread = idleThreadContainer.Top();
        idleThreadContainer.Pop();
        myThread->Assign(b);
        idleMutex.unlock();
        
        //将弹出的线程放入工作容器中
        busyMutex.lock();
        busyThreadContainer.Push(myThread);
        busyMutex.unlock();
        
        //启动线程执行任务
        myThread->StartThread();
    }
}

void MyThreadPool::AddTask(Task *task, int priority = (PRIORITY::NORMAL))
{
    task->SetPriority(priority);
    taskMutex.lock();
    taskContainer.Push(task);
    taskMutex.unlock();
}

void MyThreadPool::RemoveThreadFromBusy(MyThread *myThread)
{
    busyMutex.lock();
    std::cout << "Thread:" << myThread->GetThreadId()<< " remove from busylist" <<std::endl;
    //将一个线程从任务容器中移除并放回空闲容器中
    //使用busyMutex和idleMutex 进行加锁和解锁，确保数据的一致性
    busyThreadContainer.Erase(myThread);
    busyMutex.unlock();
    idleMutex.lock();
    idleThreadContainer.Push(myThread);
    idleMutex.unlock();
}
