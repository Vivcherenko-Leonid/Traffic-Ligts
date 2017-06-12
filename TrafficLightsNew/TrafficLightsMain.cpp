#include "TrafficLightView.h"
#include <stdio.h>

int main()
{

	char cmd;
	TrafficLightView* trafficLight = nullptr;
	do
	{
		std::cin >> cmd;
		
		switch (cmd)
		{
		case 's':
		{
			if (nullptr == trafficLight)
			{
				trafficLight = new TrafficLightView;
			}
			break;
		}
		case 'p':
			if (nullptr != trafficLight)
			{
				trafficLight->pause();
			}
			break;
		case 'i':
			break;
		default:
			break;
		}
	} while ('e' != cmd);
	if (nullptr != trafficLight)
	{
		delete trafficLight;
		trafficLight = nullptr;
	}
	return 0;
}
