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
		if (find(waitFloorDown.begin(), waitFloorDown.end(), floor) == waitFloorDown.end())
		{
			waitFloorDown.push_back(floor);			
		}
		sort(waitFloorDown.begin(), waitFloorDown.end());
	}
}
void Building::UpdateElevator()
{
	if (elevator1.IsWorking())
	{
		elevator1.UpdateStopList(waitFloorsUp);
	}
	else
	{
		if (waitFloorsUp.empty() == true && waitFloorDown.empty() == false)
		{
			if (waitFloorDown.size() > 1)
			{
				int max = *max_element(waitFloorDown.begin(), waitFloorDown.end());
				//int min = *min_element(waitFloorDown.begin(), waitFloorDown.end());
				elevator1.UpdateStopList(max);
				elevator1.SetToWork();
			}
		}
		else if (waitFloorsUp.empty() == false && waitFloorDown.empty() == true)
		{

		}
	}
}
void Building::Operate()
{
	//waitingLinesDown[13].push(peoples[297]);
	peoples[199].GetInBuilding(time);
	GetInQueue(peoples[199]);
	//elevator1.UpdateStopList(waitFloorsUp);
	cout << peoples[199].GetToFloor() << endl << endl;
}