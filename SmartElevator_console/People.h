#ifndef PEOPLE_H
#define PEOPLE_H

#include <time.h>
#include <Windows.h>

#include <iostream>

const int BUILDING_HEIGHT = 14;
struct Report
{
	int serialNum;
	int startFloor;
	int endFloor;
	int waitElevTime;
	int inElevTime;
};

class People
{	
protected:
	int serialNum;
	bool isInBuilding;
	int currentFloor;
	int toFloor;
	int startWaitTime;
	int startInTime;
	int waitElevTime;
	int inElevTime;
	bool isGoUp;
public:
	People();
	virtual ~People();
	virtual void GetInBuilding(int);
	virtual void GoingToLeave(int);
	virtual void GoingToOther(int);
	virtual void EnterElevator(int);
	virtual void LeaveElevator(int);
	virtual int GetWaitTime()const;
	virtual int GetInTime()const;	
	virtual int GetToFloor()const; 
	virtual int GetCurrentFloor()const;
	virtual bool IsGoUp()const;
	virtual Report ReportToArchive()const;
};

#endif