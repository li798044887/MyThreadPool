ThreadPool : main.o BusyThreadContainer.o IdleThreadContainer.o \
MyTask.o MyThread.o MyThreadPool.o Task.o \
TaskContainer.o
	g++ -o ThreadPool main.o BusyThreadContainer.o IdleThreadContainer.o \
MyTask.o MyThread.o MyThreadPool.o Task.o \
TaskContainer.o -lpthread 
main.o : main.cpp MyThreadPool.h MyTask.h
	g++ -c -std=c++11 main.cpp
BusyThreadContainer.o : BusyThreadContainer.cpp \
BusyThreadContainer.h MyThread.h
	g++ -c -std=c++11 BusyThreadContainer.cpp
IdleThreadContainer.o : IdleThreadContainer.cpp \
IdleThreadContainer.h MyThread.h
	g++ -c -std=c++11 IdleThreadContainer.cpp
MyTask.o : MyTask.cpp MyTask.h Task.h
	g++ -c -std=c++11 MyTask.cpp
MyThread.o : MyThread.cpp MyThread.h MyThreadPool.h \
Task.h
	g++ -c -std=c++11 MyThread.cpp
MyThreadPool.o : MyThreadPool.cpp MyThreadPool.h \
MyThread.h Task.h
	g++ -c -std=c++11 MyThreadPool.cpp
Task.o : Task.cpp Task.h
	g++ -c -std=c++11 Task.cpp
TaskContainer.o : TaskContainer.cpp TaskContainer.h
	g++ -c -std=c++11 TaskContainer.cpp
clean : 
	rm *.o

