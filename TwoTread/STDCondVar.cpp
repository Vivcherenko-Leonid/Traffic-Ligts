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
//	std::cout << "...finished waiting. i == 1\n";
	done = true;
}

void green()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "green";
	cv.notify_one(); // waiting thread is notified with i == 0.
					 // cv.wait wakes up, checks i, and goes back to waiting

	std::unique_lock<std::mutex> lk(cv_m);
	i = 1;
	while (!done)
	{
		lk.unlock();
		cv.notify_one(); // waiting thread is notified with i == 1, cv.wait returns
		std::this_thread::sleep_for(std::chrono::seconds(1));
		lk.lock();
	}
}

int main()
{
	int length = 10;
	int w;
	std::thread t1(yellow), t2(green);
	for (int j = 0; j < length; j++)
	{	std::thread t1(yellow);
	for (int k = 0; k < length; k++)
	{
		std::thread t2(green);
	}
	}

	t1.join();
	t2.join();
	std::cin >> w ;
}