#pragma once
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <queue>
#include <chrono>
#include <thread>
#include <vector>
#include <string>




class TwoTread
{
public:
	TwoTread();
	~TwoTread();
	void yellow();
	void green();
private:
	struct Color
	{
		std::string value;
		bool flag;
	};
	const std::vector<Color> colors;
};