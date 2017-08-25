#include <iostream>
#include "MyThreadPool.h"
#include "MyTask.h"

int main()
{
    //创建一个有10个线程的线程池
    MyThreadPool myThreadPool(10);
    //创建50个任务类
    MyTask j[50];
    //为创建的任务类的data字段赋值
    for(int i = 0; i < 50;i++)
    {
        j[i].SetData(i);
    }
    for(int i = 0; i < 50;i++)
    {
        myThreadPool.AddTask(&j[i],i);
    }
    int i;
    //按100添加一个任务
    //按-1结束线程池
    while(true)
    {
        std::cin >> i;
        if(i == 100)
        {
            MyTask j;
            j.SetData(i);
            myThreadPool.AddTask(&j,i);
        }
        if(i == -1)
        {
            myThreadPool.EndMyThreadPool();
            break;
        }
    }
    system("pause");
    return 0;
}
