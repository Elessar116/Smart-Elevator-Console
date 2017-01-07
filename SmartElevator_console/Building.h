#ifndef BUILDING_H
#define BUILDING_H
#include"Elevator.h"
#include <queue>
using namespace std;
class Building
{
private:
	Elevator elevator1;
	Elevator elevator2;
	//vector<int> a(1,int(10));
	vector<queue<People>> waitingLinesUp{ BUILDING_HEIGHT, queue<People>() };
	vector<queue<People>> waitingLinesDown{ BUILDING_HEIGHT, queue<People>() };
	vector<People> peoples{ 200, People() };
public:
	Building();
	~Building();
	void Operate();
};

#endif