#include "stdafx.h"
#include "People.h"
using namespace std;

People::People() :currentFloor(1), isInBuilding(false), toFloor(0), waitElevTime(0), inElevTime(0), isGoUp(false)
{
}
People::~People()
{
}
void People::GetInBuilding(int time)
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
void People::GoingToLeave(int time)
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
void People::GoingToOther(int time)
{
	currentFloor = toFloor;
	startWaitTime = time;
	do
	{
		toFloor = rand() % (BUILDING_HEIGHT - 1) + 2;
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
void People::EnterElevator(int time)
{
	waitElevTime = time - startWaitTime;
	startInTime = time;
}
void People::LeaveElevator(int time)
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