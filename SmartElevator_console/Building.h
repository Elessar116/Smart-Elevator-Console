#ifndef BUILDING_H
#define BUILDING_H
#include"Elevator.h"
#include <queue>
using namespace std;
const int PEOPLE_NUM = 200;
class Building
{
private:
	int time;
	Elevator elevator1;
	Elevator elevator2;
	//vector<int> a(1,int(10));
	vector<queue<People>> waitingLinesUp{ BUILDING_HEIGHT, queue<People>() };
	vector<queue<People>> waitingLinesDown{ BUILDING_HEIGHT, queue<People>() };
	vector<int> waitFloorsUp;
	vector<int> waitFloorDown;
	vector<People> peoples{ PEOPLE_NUM, People() };
public:
	Building();
	virtual~Building();	
	virtual void GetInQueue(People);
	virtual void UpdateElevator();

	virtual void Operate();
};

#endif