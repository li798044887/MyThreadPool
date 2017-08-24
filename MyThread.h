#pragma once

#include <thread>

class MyThreadPool;
class Task;
class MyThread;

class MyThread
{
    //重载 == 和 ！=运算符
    friend bool operator == (MyThread my1, MyThread my2);
    friend bool operator != (MyThread my1, MyThread my2);
public:
    //构造一个MyThread对象，将自己与指定的线程池相关联起来
    MyThread(MyThreadPool *pool);
    //将一个任务与该线程相关联起来
    void Assign(Task *task);
    //调用Task的Run方法，同时在Task的Run方法结束后将自己从工作容器
    //移回空闲容器
    void Run();
    //执行线程的Run方法，即执行Task的Run方法
    void StartThread();
    //获取线程的id号
    int GetThreadId();
    //设置线程在在运行的时候是join还是detach的
    void SetIsDetach(bool isDetach);
private:
    MyThreadPool *myThreadPool;
    static int s_threadNumber;
    bool isDetach;
    Task *task;
    int threadId;
    std::thread thread;
};
