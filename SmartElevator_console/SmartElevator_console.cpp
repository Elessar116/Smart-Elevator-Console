// SmartElevator_console.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include "Building.h"
#include "Elevator.h"
#include "People.h"
//#include <Windows.h>
#include <chrono>
#include <vector>
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
	vector<Report> arc;
	//vector<Report> arc2;
	People p1,p2;
	p1.GetInBuilding(1);
	p1.EnterElevator(7);
	p1.LeaveElevator(15);
	
	//cout << p1.GetWaitTime() << endl;
	//cout << p1.GetInTime() << endl;
	//cout << p1.ReportToArchive().waitElevTime << endl;
	//cout << p1.ReportToArchive().inElevTime << endl;
	arc.push_back(p1.ReportToArchive());
	cout << arc[0].waitElevTime << endl;
	cout << arc[0].inElevTime << endl;
	
	p1.GoingToOther(20);
	p1.EnterElevator(29);
	p1.LeaveElevator(40);

	//cout << p1.GetWaitTime() << endl;
	//cout << p1.GetInTime() << endl;
	//cout << p1.ReportToArchive().waitElevTime << endl;
	//cout << p1.ReportToArchive().inElevTime << endl;
	arc.push_back(p1.ReportToArchive());
	cout << arc[1].waitElevTime << endl;
	cout << arc[1].inElevTime << endl;
	//p1.ReportToArchive(arc);
	
	p2.GetInBuilding(2);
	//p2.ReportToArchive(arc);
	

	Elevator v1;
	v1.PeopleEnter(p1);
	cout << v1.IsFull() << endl;

	Building b1;
	b1.Operate();
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

