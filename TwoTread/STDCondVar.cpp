#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <future>
#include <cstdlib>

std::condition_variable cv;
std::mutex cv_m;
int i = 0;
bool done = false;

void clearScreen()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif

}

void yellow()
{
	std::cout << "yellow" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	clearScreen();
}

void green()
{
	std::cout << "green";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	clearScreen();
}

int main()
{
	int length = 10;
	int w;
	

	while (true)
	{
		std::thread t2(green);
	}
	while (true)
	{
		std::thread t1(yellow);
	}
	std::thread t1(yellow), t2(green);
	t1.join();
	t2.join();
	std::cin >> w ;
}