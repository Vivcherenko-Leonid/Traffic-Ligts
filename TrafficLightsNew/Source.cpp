#include <iostream>
#include <windows.h>

const int row = 10;
const int col = 10;

void fillArray(char (&arr)[row][col], bool isEmpry);
void printArr(char (&arr)[row][col]);
void trafficLight(char (&empty)[row][col], char(&full)[row][col]);

int main(int count, char* strings[])
{
	/*EXAMPLE of arguments getting from CMD
	std::cout << count << std::endl;
	std::cout << strings[0] << std::endl ;
	if (count > 1) std::cout << strings[1] << std::endl;*/
	//char arr1[row][col];
	//char arr2[row][col];
	//fillArray(arr1, true);
	//fillArray(arr2, false);
	//trafficLight(arr1, arr2);

	int x = 10;
	int* xPtr = &x;
	int& y = x;
	y++;
	(*xPtr)++;
	
	std::cout << x << std::endl;
	std::cout << xPtr << std::endl;
	xPtr++;
	std::cout << xPtr << std::endl;
	std::cout << *xPtr << std::endl;
	std::cout << y << std::endl;
	return 0;
}


void fillArray(char(&arr)[row][col], bool isEmpty)
{
	char first ('X');
	char second ('C');
	if (isEmpty) second = ' ';
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			if (0 == i || row - 1 == i || 0 == k || col - 1 == k || 1 == i || row - 2 == i || 1 == k || col - 2 == k)
			{
				arr[i][k] = first;
			}
			else arr[i][k] = second;
		}
	}
}

void printArr(char(&arr)[row][col])
{
	std::cout << std::endl;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			std::cout << arr[i][k] << " ";
		}
		std::cout << std::endl;
	}
}

void trafficLight(char(&empty)[row][col], char(&full)[row][col])
{
	int iter = 0;
	while (iter != 100)
	{
		if (0 == iter)
		{
			printArr(full);
			printArr(empty);
			printArr(empty);
		}
		else
		{
			if (!(iter % 3))
			{
				printArr(empty);
				printArr(empty);
				printArr(full);
			}
			else if (!(iter % 2))
			{
				printArr(empty);
				printArr(full);
				printArr(empty);
			}
			else
			{
				printArr(full);
				printArr(empty);
				printArr(empty);
			}
		}
		iter++;
		Sleep(2000);
	}
}
