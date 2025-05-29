#include<iostream>
#include<list>
#include<thread>
#include<future>
#include<mutex>
#include<WINDOWS.h> //for getting handle

using namespace std;
const int SIZE_ = 300000;
std::list<int> gData;
std::mutex gMutex;

//Process: It is an indpendent program in execution. When you run a program, OS creates a process for it. Processes do not share memory with other process.
// //Thread: is smallest unit of execution within process. Multiple threads can share memory.
//efficient usage of CPU
//create multiple threads
//Larger application require some of its components to execute concurrently.
/*
Thread Synchronization: When 2 download functions access the same list gData to push data in it. It caused race condition
and the size of list was incomplete. But after adding mutex, the 2 threads will access the gData list only if its free and wait if it is not.
Hence now the data size is 600000.
* Generally, mutex lock should be avoided, where other thread has to wait for other thread. What we can do is create separate lists for 2 threads 
* and threads have joined/ completed , we could combine the 2 lists. This way the performance of the code would improve.

task based concurrency: instead of managing threads, manage tasks.
High-level concurrency: async,future,packaged_task. limited ,safer and easier
low level concurrency: pthread,std::thread,std::mutex. maximum flexibility
*/

void Download(const std::string& file )
{
	cout << "download start" <<file<< endl;
	for (int i = 0;i < SIZE_;++i)
	{
		gMutex.lock();
		gData.push_back(i);
		//if (i == 500)               //If the thread returns without unlocking mutex, it causes deadlock condition.
			//return;
		gMutex.unlock();
	}
	cout << "download finish" << endl;
}

void Download2(const std::string& file)
{
	cout << "download2 start" << file << endl;
	for (int i = 0;i < SIZE_;++i)
	{
		std::lock_guard<std::mutex> mtx(gMutex); //It will lock mutex and unlock at end of scope automatically.C++11 feature
		//gMutex.lock();
		gData.push_back(i);
		//gMutex.unlock();
	}
	cout << "download2 finish" << endl;
}

int AddOp(int a, int b)
{
	for (int i = 0;i < 15;++i)
	{
		cout << "--";
	}
	return a + b;
}

void process()
{
	cout << "Inside thread:id:" << std::this_thread::get_id() << endl;
	for (int i = 0;i < 10;++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << i << endl;
	}
}

//main is blocked until download operation is over.
int main()
{
	cout << "User start" << endl;
	std::string filename("cpp");
	std::thread thDownload(Download,std::cref(filename));// cref for const ref, ref for passing reference. otherwise a copy will be created in thread even if & used..
	std::thread thDownload2(Download2, std::cref(filename));

	//thDownload.detach(); //joinable thread can be detached. but once detach you cannot make it joinable.
	//call detach if you dont want to wait for thread to complete with join.
    
	//packaged_task is a template class that wraps any callable(function,lambda,functor) and allows the result to be accessed through future
	//future helps to store the result data.

	std::packaged_task<int(int, int)> taskAdd(AddOp);
	std::future ft = taskAdd.get_future();
	std::thread thAdd(std::move(taskAdd),3,5); //calling Add function with thread
	//taskAdd(3, 5);                           //calling function without thread
	cout << ft.get() << endl;

	cout << "User end" << endl;
	if (thDownload.joinable())
	{
		thDownload.join(); //wait for thread to finish; otherwise main thread will exit with exit function.
	}

	std::thread t1(process);
	std::cout << "process id"<<t1.get_id() << endl;
	HANDLE handle = t1.native_handle();  //native handle for linux is pthread_t 
	SetThreadDescription(handle, L"T1 thread");
	int cores = std::thread::hardware_concurrency();
	cout << "No. of cores" << cores << endl; //for optimum efficience ideally threads created should equal to number of cores

	//Using Task based concurrency -1
	//async takes callable in separate thread and returns future object for result
	std::future<void> res= std::async(Download,std::cref(filename)); //requires future header file
	/*returns object of type future, it is imp to get the future object, otherwise 
	the temp object created will block the main thread 	async creates copy
	*/
	cout << "Main thread continues execution" << endl;
	res.get(); //makes thread wait like join

	t1.join();
	thAdd.join();
	thDownload2.join();
	cout << gData.size() << endl;

	return 0;
}