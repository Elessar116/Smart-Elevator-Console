#include "stdafx.h"
#include "People.h"
using namespace std;
People::People() :currentFloor(1), isInBuilding(false), toFloor(0), waitElevTime(0), inElevTime(0)
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
	
}
void People::GoingToLeave(int time)
{
	startWaitTime = time;
	toFloor = 1;
}
void People::GoingToOther(int time)
{
	startWaitTime = time;
	do
	{
		toFloor = rand() % (BUILDING_HEIGHT - 1) + 2;
	} while (toFloor == 1 || toFloor == currentFloor);
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

//void People::AddWaitTime(int waitTime)
//{
//	waitElevTime += waitTime;
//}
//void People::AddInTime(int inTime)
//{
//	inElevTime += inTime;
//}
