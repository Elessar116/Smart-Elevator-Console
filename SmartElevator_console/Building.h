#ifndef BUILDING_H
#define BUILDING_H
#include"Elevator.h"
#include <queue>
using namespace std;
const int PEOPLE_NUM = 500;
class Building
{
private:
	int time;
	Elevator elevator1;
	Elevator elevator2;	
	vector<queue<People>> waitingLinesUp{ BUILDING_HEIGHT, queue<People>() };
	vector<queue<People>> waitingLinesDown{ BUILDING_HEIGHT, queue<People>() };
	vector<vector<People>> floors{ BUILDING_HEIGHT, vector<People>() };
	vector<int> waitFloorsUp;
	vector<int> waitFloorsDown;
	vector<People> peoples{ PEOPLE_NUM, People() };
	vector<Report> archive;
public:
	Building();
	virtual~Building();	
	virtual void GetInQueue(People);
	virtual void UpdateElevator();
	virtual void GetPeopleIn(const int time);
	virtual void GetPeopleToOther(const int time);
	virtual void Operate();
	virtual int GetTime()const;
};

#endif