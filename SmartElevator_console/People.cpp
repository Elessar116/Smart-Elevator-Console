#include "stdafx.h"
#include "People.h"
using namespace std;

People::People() :serialNum(0),currentFloor(1), isInBuilding(false), toFloor(0), waitElevTime(0), inElevTime(0), isGoUp(false)
{
}
People::~People()
{
}
void People::GetInBuilding(const int time)
{
	startWaitTime = time;
	currentFloor = 1;
	isInBuilding = true;
	do
	{
		toFloor = (rand() % BUILDING_HEIGHT) - 1;
	} while (toFloor == 1);
	if (toFloor > currentFloor)
	{
		isGoUp = true;
	}
	else
	{
		isGoUp = false;
	}
}
void People::GoingToLeave(const int time)
{
	currentFloor = toFloor;
	startWaitTime = time;
	toFloor = 1;
	if (toFloor > currentFloor)
	{
		isGoUp = true;
	}
	else
	{
		isGoUp = false;
	}
}
void People::GoingToOther(const int time)
{
	currentFloor = toFloor;
	startWaitTime = time;
	do
	{
		toFloor = (rand() % BUILDING_HEIGHT) - 1;
	} while (toFloor == 1 || toFloor == currentFloor);
	if (toFloor > currentFloor)
	{
		isGoUp = true;
	}
	else
	{
		isGoUp = false;
	}
}
void People::EnterElevator(const int time)
{
	waitElevTime = time - startWaitTime;
	startInTime = time;
}
void People::LeaveElevator(const int time)
{
	inElevTime = time - startInTime;
}


int People::GetWaitTime()const
{
	return waitElevTime;
}
int People::GetInTime()const
{
	return inElevTime;
}
int People::GetToFloor()const
{
	return toFloor;
}
int People::GetCurrentFloor()const
{
	return currentFloor;
}
bool People::IsGoUp()const
{
	return isGoUp;
}
Report People::ReportToArchive()const
{
	Report report;
	report.serialNum = serialNum;
	report.startFloor = currentFloor;
	report.endFloor = toFloor;
	report.waitElevTime = waitElevTime;
	report.inElevTime = inElevTime;
	return report;
}