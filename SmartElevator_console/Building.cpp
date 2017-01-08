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
			elevator1.UpdateStopList(max);//�i��X�{�w�g���A���Ӫ����p�n�`�N
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
			elevator1.UpdateStopList(min);//�i��X�{�w�g���A���Ӫ����p�n�`�N
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
			elevator1.SetToRest();
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
	//elevator1.UpdateStopList(waitFloorsUp);
	cout << endl << peoples[199].GetToFloor() << endl << endl;
}