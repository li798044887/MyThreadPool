#pragma once

namespace
{
	enum  PRIORITY
	{

		MIN = 1, NORMAL = 25, MAX = 50
	};
}

class Task
{
public:
    Task()
    {
    
    }
    //设置任务的优先级
    void SetPriority(int priority)
    {
        if(priority > (PRIORITY::MAX)){
            priority = (PRIORITY::MAX);
        } 
        else if (priority < (PRIORITY::MIN)){
            priority = (PRIORITY::MIN);
        }
    }
    //线程执行的方法，需要子类实现
    virtual void Run() = 0;
protected:
    int priority;
};
