
#include <iostream>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <windows.h>



int flg = 0;

std::mutex flagGuard;
std::mutex coutGuard;

void red()
{
	while (true)
	{
		if (!flg) {
			return;
		}

		if (1 == flg)
		{
			coutGuard.lock();
			std::cout << "Red" << std::endl;
			std::cout.flush();
			Sleep(2000);
			system("cls");
			coutGuard.unlock();
		}
	}
}

void yellow() {
	while (true)
	{
		if (!flg) {
			return;
		}

		if (2 == flg)
		{
			coutGuard.lock();
			std::cout << "Yellow" << std::endl;
			std::cout.flush();
			Sleep(500);
			system("cls");
			Sleep(500);
			coutGuard.unlock();
		}
	}
}

void green() {
	while (true)
	{
		if (!flg) {
			return;
		}

		if (3 == flg)
		{
			coutGuard.lock();
			std::cout << "Green" << std::endl;
			std::cout.flush();
			Sleep(2000);
			system("cls");
			coutGuard.unlock();
		}
	}
}

int main()
{
	flg = 1;
	system("cls");
	std::thread redThread(red);
	std::thread yellowThread(yellow);
	std::thread greenThread(green);

	for (int i = 0; i < 12; i++)
	{
		Sleep(5000);
		flagGuard.lock();
		++flg;
		flg %=  4;
		if (!flg) ++flg;
		flagGuard.unlock();
	}

	flagGuard.lock();
	flg = 0;
	flagGuard.unlock();
	Sleep(500);
	std::cout << "Stopping threads" << std::endl;
	Sleep(2000);
	if (greenThread.joinable() && yellowThread.joinable() && redThread.joinable())
	{

		greenThread.join();
		yellowThread.join();
		redThread.join();
		std::cout << "Threads have been stopped successfully" << std::endl;
		Sleep(2000);
	}
	else
	{
		std::cout << "Can't join threads" << std::endl;
		Sleep(2000);
	}

	int w;
	std::cin >> w;

	return 0;
}


















































































//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <stdio.h>
////#include <unistd.h>
//#include <windows.h>
//
//
//bool isRunning;
//bool Green;
//bool Yellow;
//int flag = true;
//
//std::mutex flagGuard;
//std::mutex coutGuard;
//
//void green() {
//	while (true)
//	{
//		if (!flag) {
//			return;
//		}
//
//		if (flag)
//		{
//			coutGuard.lock();
//			std::cout << "Green" << std::endl;
//			std::cout.flush();
//			Sleep(2000);
//			system("cls");
//			coutGuard.unlock();
//		}
//	}
//}
//
//void yellow() {
//	while (true)
//	{
//		//flagGuard.lock();//std::lock_guard<std::mutex> lock(flagGuard);
//		if (!flag) {
//			return;
//		}
//		//flagGuard.unlock();	
//
//		if (flag)
//		{
//			coutGuard.lock();
//			std::cout << "Yellow" << std::endl;
//			std::cout.flush();
//			Sleep(500);
//			system("cls");
//			std::cout.flush();
//			Sleep(500);
//			coutGuard.unlock();
//		}
//	}
//}
//
//int main()
//{
//	 flag = true;
//	//isRunning = true;
//	//flag = !flag;
//	//Yellow = !Green;
//	system("cls");
//	std::thread greenThread(green);
//	std::thread yellowThread(yellow);
//
//	for (int i = 0; i < 10; i++)
//	{
//		Sleep(4000);
//		flagGuard.lock();
//		flag  = true;
//		
//		flagGuard.unlock();
//		flag = !flag;
//	}
//
//	flagGuard.lock();
//	flag = false;
//	flagGuard.unlock();
//	Sleep(5000);
//	std::cout << "Stopping threads" << std::endl;
//	Sleep(2000);
//	if (greenThread.joinable() && yellowThread.joinable())
//	{
//
//		greenThread.join();
//		yellowThread.join();
//		std::cout << "Threads have been stopped successfully" << std::endl;
//		Sleep(2000);
//	}
//	else
//	{
//		std::cout << "Can't join threads" << std::endl;
//		Sleep(2000);
//	}
//
//	int w;
//	std::cin >> w;
//
//	return 0;
//}
