// SmartElevator_console.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include "Building.h"
#include "Elevator.h"
#include "People.h"
//#include <Windows.h>
#include <chrono>
using namespace std;

//template <class Clock>
//void
//display_precision()
//{
//	typedef std::chrono::duration<double, std::nano> NS;
//	NS ns = typename Clock::duration(1);
//	std::cout << ns.count() << " ns\n";
//}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(static_cast<unsigned int>(time(NULL)));
	cout << "hello elevator" << endl;
	std::chrono::high_resolution_clock::time_point start, end;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		int a = i*i*i;

		//cout << a;
	}
	end = std::chrono::high_resolution_clock::now();
	auto duration = end - start;
	cout << endl << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << endl;//
	cout << (double)std::chrono::system_clock::period::num
		 << endl << std::chrono::system_clock::period::den <<endl;
	/*display_precision<std::chrono::high_resolution_clock>();
	display_precision<std::chrono::system_clock>();*/
	return 0;
}

