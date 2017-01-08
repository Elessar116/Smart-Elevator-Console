#include "stdafx.h"
#include "Building.h"
#include <algorithm>
using namespace std;

Building::Building() :time(0), elevator1(), elevator2()
{
}
Building::~Building()
{
}
void Building::GetInQueue(People people)
{
	int floor = people.GetCurrentFloor();
	if (people.IsGoUp())
	{
		waitingLinesUp[floor + 1].push(people);
		if (find(waitFloorsUp.begin(), waitFloorsUp.end(), floor) == waitFloorsUp.end())
		{
			waitFloorsUp.push_back(floor);			
		}
		sort(waitFloorsUp.begin(), waitFloorsUp.end());
	}
	else
	{
		waitingLinesDown[floor + 1].push(people);
		if (find(waitFloorsDown.begin(), waitFloorsDown.end(), floor) == waitFloorsDown.end())
		{
			waitFloorsDown.push_back(floor);			
		}
		sort(waitFloorsDown.begin(), waitFloorsDown.end());
	}
}
void Building::UpdateElevator()
{
	if (elevator1.IsWorking())
	{
		if (elevator1.IsGoUp())
		{
			for_each(waitFloorsUp.begin(), waitFloorsUp.end(), \
				[&](int x){if (x > elevator1.GetCurrentFloor())elevator1.UpdateStopList(x); });
		}
		else
		{
			for_each(waitFloorsDown.begin(), waitFloorsDown.end(), \
				[&](int x){if (x < elevator1.GetCurrentFloor())elevator1.UpdateStopList(x); });
		}
	}
	else
	{
		if (waitFloorsUp.empty() == true && waitFloorsDown.empty() == false)
		{			
			int max = *max_element(waitFloorsDown.begin(), waitFloorsDown.end());
			elevator1.UpdateStopList(max);//可能出現已經停再那樓的情況要注意
			elevator1.SetToWork();
			if (max > elevator1.GetCurrentFloor())
			{
				elevator1.SetToUp();
			}
			else
			{
				elevator1.SetToDown();
			}
		}
		else if (waitFloorsUp.empty() == false && waitFloorsDown.empty() == true)
		{
			int min = *min_element(waitFloorsUp.begin(), waitFloorsUp.end());
			elevator1.UpdateStopList(min);//可能出現已經停再那樓的情況要注意
			elevator1.SetToWork();
			if (min < elevator1.GetCurrentFloor())
			{
				elevator1.SetToDown();
			}
			else
			{
				elevator1.SetToUp();
			}
		}
		else if (waitFloorsUp.empty() == false && waitFloorsDown.empty() == false)
		{
			int upMin = *min_element(waitFloorsUp.begin(), waitFloorsUp.end());
			int downMax = *max_element(waitFloorsDown.begin(), waitFloorsDown.end());
			int distanceUp = abs(elevator1.GetCurrentFloor() - upMin);
			int distanceDown = abs(elevator1.GetCurrentFloor() - downMax);
			if (distanceUp < distanceDown)
			{
				elevator1.UpdateStopList(upMin);
				elevator1.SetToWork();
				if (upMin < elevator1.GetCurrentFloor())
				{
					elevator1.SetToDown();
				}
				else
				{
					elevator1.SetToUp();
				}
			}
			else
			{
				elevator1.UpdateStopList(downMax);
				elevator1.SetToWork();
				if (downMax > elevator1.GetCurrentFloor())
				{
					elevator1.SetToUp();
				}
				else
				{
					elevator1.SetToDown();
				}
			}
			
		}
		else
		{
			elevator1.SetToRest();//do something when rest
		}
	}
}
void Building::Operate()
{
	//waitingLinesDown[13].push(peoples[297]);
	peoples[199].GetInBuilding(time);
	GetInQueue(peoples[199]);
	
	if (waitFloorsUp.empty() == false)
	{
		for_each(waitFloorsUp.begin(), waitFloorsUp.end(), [](int x){cout << "up floors: " << x << " "; });
		cout << endl;
	}
	if (waitFloorsDown.empty() == false)
	{
		for_each(waitFloorsDown.begin(), waitFloorsDown.end(), [](int x){cout << "down floors: " << x << " "; });
		cout << endl;
	}

	UpdateElevator();
	cout << elevator1.IsWorking() << endl;
	cout << elevator1.IsGoUp() << endl;
	elevator1.ShowStopList();
	elevator1.Work(time);
	elevator1.OpenDoor(time);
	//cout << waitFloorsUp.empty() << endl;
	
	//peoples[199].EnterElevator(time);
	if (elevator1.IsFull() == false)
	{
		elevator1.PeopleEnter(peoples[199],time);
	}
	elevator1.ShowStopList();
	elevator1.CloseDoor(time);
	//cout << "go up: " << elevator1.IsGoUp() << endl;
	elevator1.Work(time);
	elevator1.OpenDoor(time);
	vector<People> leave = elevator1.PeopleLeave(time);
	for_each(leave.begin(), leave.end(), [&](People& p){archive.push_back(p.ReportToArchive()); });
	for_each(leave.begin(), leave.end(), [&](People& p){floors[elevator1.GetCurrentFloor() + 1].push_back(p); });
	leave.clear();
	//cout << "floor people : " << floors[elevator1.GetCurrentFloor() + 1][0].GetInTime() << endl;

	elevator1.CloseDoor(time);
	cout << "arc wait: " << archive[0].waitElevTime << endl;
	cout << "arc in: " << archive[0].inElevTime << endl;
	cout << "wait time: " << leave[0].GetWaitTime() << endl;
	cout << "in time: " << leave[0].GetInTime() << endl;
	//peoples[199].LeaveElevator(time);
	cout << "floor: " << elevator1.GetCurrentFloor() << endl;
	elevator1.ShowStopList();
	cout << "time: " << time << endl;
	//cout << "wait time: " << peoples[199].GetWaitTime() << endl;
	//cout << "in time: " << peoples[199].GetInTime() << endl;
	cout << "op time: " << elevator1.GetOpTime() << endl;



	//cout << time << endl;
	//elevator1.UpdateStopList(waitFloorsUp);
	cout << peoples[199].GetToFloor() << endl << endl;
}
int Building::GetTime()const
{
	return time;
}