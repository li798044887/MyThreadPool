#pragma once

#include <vector>

class MyThread;
class MyThreadPool;

class IdleThreadContainer
{

public:
    IdleThreadContainer();
    //负责析构空闲容器中的线程
    ~IdleThreadContainer();
    //返回空闲容器的大小
    std::vector<MyThread*>::size_type Size();
    //将一个线程放回空闲容器中
    void Push(MyThread *m);
    //创建n个线程与线程池m相关联的线程放入空闲容器中
    void Assign(int n,MyThreadPool* m);
    //返回位于空闲容器顶端的线程
    MyThread* Top();
    //弹出空闲容器顶端的线程
    void Pop();
    //删除一个指定的线程
    void Erase(MyThread *m);

private:
    std::vector<MyThread*> idleThreadContainer;
    typedef std::vector<MyThread*> Container;
    typedef Container::iterator Iterator;
};