#include "Task.h"

class MyTask :public Task
{
    //用于比较两个任务的优先级
    friend bool operator<(MyTask &lv,MyTask &rv)
    {
        return lv.priority < rv.priority;
    }
public:
    MyTask();
    ~MyTask();
    //自定义的Run方法
    virtual void Run();
    //设置数据
    void SetData(int d);
private:
    int data;
};
