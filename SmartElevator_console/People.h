#ifndef PEOPLE_H
#define PEOPLE_H
#define BUILDING_HEIGHT 14
#include <time.h>
#include <Windows.h>
class People
{	
protected:
	int serialNum;
	bool isInBuilding;
	int currentFloor;
	int toFloor;
	int startWaitTime;
	int endWaitTime;
	int startInTime;
	int endInTime;
	int waitElevTime;
	int inElevTime;
public:
	People();
	//People();
	virtual ~People();
	virtual void GetInBuilding(int);
	virtual void GoingToLeave(int);
	virtual void GoingToOther(int);
	virtual void EnterElevator(int);
	virtual void LeaveElevator(int);
	//virtual void AddWaitTime(int);
	//virtual void AddInTime(int);
	virtual int GetWaitTime();
	virtual int GetInTime();
	virtual void ReportToArchive();
};

#endif