#include "BusyThreadContainer.h"
#include "MyThread.h"

BusyThreadContainer::BusyThreadContainer()
{
}

BusyThreadContainer::~BusyThreadContainer()
{
}

void BusyThreadContainer::push(MyThread *m)
{
    //将线程放入工作容器
    busyThreadContainer.push_back(m);
}

void BusyThreadContainer::Erase(MyThread *m)
{
    //在容器中查找目标线程并释放
    busyThreadContainer.erase(find(busyThreadContainer.begin(),busyThreadContainer.end(),m));
    
}

std::list<MyThread*>::size_type 
BusyThreadContainer::Size()
{
    return busyThreadContainer.size();
}
