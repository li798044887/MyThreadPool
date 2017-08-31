#include <iostream>
#include <algorithm>
#include "IdleThreadContainer.h"
#include "MyThread.h"

IdleThreadContainer::IdleThreadContainer()
{
}

//析构空闲容器类
IdleThreadContainer::~IdleThreadContainer()
{
    int i = 0;
    for(auto it = idleThreadContainer.begin();it!=idleThreadContainer.end();it++)
    {
        std::cout<<i++<<std::endl;
        delete *it;
    }
}

std::vector<MyThread*>::size_type IdleThreadContainer::Size()
{
    return idleThreadContainer.size();
}

void IdleThreadContainer::Push(MyThread *m)
{
    idleThreadContainer.push_back(m);
}

void IdleThreadContainer::Pop()
{
    idleThreadContainer.pop_back();
}

void IdleThreadContainer::Erase(MyThread *m)
{
    idleThreadContainer.erase(std::find(idleThreadContainer.begin(),idleThreadContainer.end(),m));
}

//向空闲容器添加number个线程
void IdleThreadContainer::Assign(int number,MyThreadPool *m)
{
    for(int i = 0;i <number; i++)
    {
        MyThread *p = new MyThread(m);
        idleThreadContainer.push_back(p);
    }
}

MyThread* IdleThreadContainer::Top()
{
    return idleThreadContainer.back();
}



