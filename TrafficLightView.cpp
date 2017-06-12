#include "TrafficLightView.h"
#include <future>


TrafficLightView::TrafficLightView()
	: flag(true)
	, signals {{ "RED",    4,   true }, { "Yellow", 5,   false }, { "Green",  6,   true }}
{
	std::async(std::launch::async, &TrafficLightView::view, this);
}


TrafficLightView::~TrafficLightView()
{
}

void TrafficLightView::clear()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif

}

void TrafficLightView::view()
{
	while (flag)
	{
		for (const auto& s : signals)
		{
			clear();
			if (s.constant)
			{
				viewConstant(s);
			}
			else
			{
				yellow(s);
			}
		}
	}
}

void TrafficLightView::viewConstant(Signal signal)
{
	std::cout << signal.value << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(signal.seconds));
}

void TrafficLightView::yellow(Signal signal)
{
	size_t sec = signal.seconds;
	while (sec)
	{
		if (sec % 2)
		{
			std::cout << signal.value << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		clear();
		sec--;
	}
}


