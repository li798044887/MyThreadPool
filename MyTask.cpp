#include <iostream>
#include <thread>
#include "MyTask.h"

MyTask::MyTask()
{
}

MyTask::~MyTask()
{
}

void MyTask::SetData(int d)
{
    data = d;
}

void MyTask::Run()
{
    std::cout << "Hello I am"<<data<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
