//#pragma once
//#include <iostream>
//#include <chrono>
//#include <cstdlib>
//#include <thread>
//#include <vector>
//#include <string>
//
//class TrafficLightView
//{
//public:
//	TrafficLightView();
//	~TrafficLightView();
//	void view();
//	inline void pause();
//	inline void release();
//private:
//	struct Signal
//	{
//		std::string value;
//		size_t      seconds;
//		bool        constant;
//	};
//
//	void clear();
//	void viewConstant(Signal s);
//	void yellow(Signal s); 
//private:
//	bool flag;
//	const std::vector<Signal> signals;
//};
//
//inline void TrafficLightView::pause()
//{
//	flag = false;
//}
//
//inline void TrafficLightView::release()
//{
//	flag = true;
//}
//
