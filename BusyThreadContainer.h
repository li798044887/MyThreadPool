#pragma once

#include <list>

class MyThread;

class BusyThreadContainer
{

public:
    BusyThreadContainer();
    ~BusyThreadContainer();
    //将一个线程放入工作容器中
    void Push(MyThread *m);
    //返回工作容器的大小
    std::list<MyThread*>::size_type Size();
    //删除一个指定的线程
    void Erase(MyThread *m);

private:
    std::list<MyThread*> busyThreadContainer;
    typedef std::list<MyThread*> Container;
    typedef std::list<MyThread*>::iterator Iterator;
};
