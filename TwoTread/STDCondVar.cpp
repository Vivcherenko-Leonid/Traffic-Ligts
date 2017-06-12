#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m;
int i = 0;
bool done = false;

void yellow()
{
	std::unique_lock<std::mutex> lk(cv_m);
	std::cout << "yellow \n";
	cv.wait(lk, [] {return i == 1; });
	done = true;
}

void green()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "green";
	cv.notify_one();

	std::unique_lock<std::mutex> lock(cv_m);
	i = 1;
	//while (!done)
	//{
	//	lock.unlock();
	//	cv.notify_one();
	//	std::this_thread::sleep_for(std::chrono::seconds(1));
	//	lock.lock();
	//}
}

int main()
{
	int length = 10;
	int w;
	std::thread t1(yellow), t2(green);
	for (int j = 0; j < length; j++)
	{
		std::thread t1(yellow);
		for (int k = 0; k < length; k++)
		{
			std::thread t2(green);
		}
	}
	//	else
	//	{
	//	
	//}

	t1.join();
	t2.join();
	std::cin >> w ;
}