#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <chrono>
#include <condition_variable>


enum THREAD_CONTROL
{
    THREAD_RUN,
    THREAD_PAUSE,
    THREAD_STOP,

    THREAD_INVALID
};

THREAD_CONTROL g_threadStatus = THREAD_INVALID;
std::mutex g_threadMutex;
std::condition_variable g_threadcv;

void ThreadRun()
{
    if (g_threadStatus == THREAD_PAUSE)
    {
        std::unique_lock<std::mutex> lck(g_threadMutex);
        g_threadStatus = THREAD_RUN;
        g_threadcv.notify_all();
    }
}

void ThreadPause()
{
	if (g_threadStatus == THREAD_RUN)
	{
		std::unique_lock<std::mutex> lck(g_threadMutex);
		g_threadStatus = THREAD_PAUSE;
	}
}

void ThreadStop()
{
	// 在暂停状态点击了停止，需要先让线程解除阻塞，然后才停止
	if (g_threadStatus == THREAD_PAUSE)
	{
		std::unique_lock<std::mutex> lck(g_threadMutex);
		g_threadStatus = THREAD_STOP;
		g_threadcv.notify_all();
	}
	else
	{
		std::unique_lock<std::mutex> lck(g_threadMutex);
		g_threadStatus = THREAD_STOP;
	}
}

void printThreadID(int num)
{
	while(1)
	{
		std::cout << "the thread NO is:" << num << ", ID is:" << std::this_thread::get_id() << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));

		// while 判断条件, 防止虚假唤醒
		while (g_threadStatus == THREAD_PAUSE)
		{
			std::cout << "thread " << num << " pause!\n";
			std::unique_lock<std::mutex> tmp(g_threadMutex);
			g_threadcv.wait(tmp);
		}

		if (g_threadStatus == THREAD_STOP)
		{
			std::cout << "thread " << num << " stop!\n";
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	g_threadStatus = THREAD_RUN;
	std::cout << "按任意键开始:\n";
	std::cout << "开始之后输入数字控制线程: 1-暂停, 2-继续, 3-停止:\n";
	std::string tmp;
	std::cin >> tmp;

	// 使用容器管理线程
	std::vector<std::thread> vecThread;
	for (int i = 0; i < 4; ++i)
	{
		vecThread.push_back(std::thread(printThreadID, i));
	}

	// 开始手动控制线程
	int cmd = -1;
	while (std::cin >> cmd)
	{
		switch (cmd)
		{
			case 1:
			{
				ThreadPause();
				break;
			}
			case 2:
			{
				ThreadRun();
				break;
			}
			case 3:
			{
				ThreadStop();
				break;
			}
			default:
			{
				break;
			}
		}

		if (3 == cmd)
		{
			break;
		}
	}
	// 回收线程
	for (unsigned int i = 0; i < vecThread.size(); ++i)
	{
		if (vecThread[i].joinable())
		{
			vecThread[i].join();
		}
	}

	return 0;
}
