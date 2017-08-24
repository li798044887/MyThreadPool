#include <iostream>
#include "MyThread.h"
#include "MyThreadPool.h"
#include "Task.hpp"

int MyThread::s_threadNumber = 0;
MyThread::MyThread(MyThreadPool *pool):myThreadPool(pool),isDetach(true)
{
    s_threadNumber++;
    threadId = s_threadNumber;
}

void MyThread::SetIsDetach(bool detach)
{
    isDetach = detach;
}

void MyThread::Assign(Task *t)
{
    task = t;
}
void MyThread::Run()
{
    //调用Task的Run方法
    cout <<"Thread:"<< threadId <<" run ";
    task->Run();
    //结束Task的Run方法结束互后，通知线程池将自己从工作容器移回空闲容器
    myThreadPool->RemoveThreadFromBusy(this);
}

int MyThread::GetThreadId()
{
    return threadId;
}

void MyThread::StartThread()
{
    //将MyThread的Run方法与thread绑定，this表示类的Run方法的第一个隐含参数
    thread = thread(&MyThread::Run, this);
    //根据isDetach的值，判断线程的启动状态为detach或join
    if(isDetach == true)
        thread.detach();
    else
        thread.join();
}

bool operator == (MyThread my1, MyThread my2)
{
    return my1.threadId == my2.threadId;
}

bool operator != (MyThread my1, MyThread my2)
{
    return !(my1.threadId == my2.threadId);
}
