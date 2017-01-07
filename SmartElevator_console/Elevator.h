#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <vector>
#include "People.h"
using namespace std;
#define CAPACITY 12
class Elevator
{
private:
	int currentFloor;
	int currentPeople;
	const int capacity = CAPACITY;
	int totalOpTime;
	vector<int> stopList;
	vector<People> peoples;
	bool isWorking;
public:
	Elevator();
	~Elevator();
	//void MoveUp();
	//void MoveDown();
	void MoveTo(int floor);
	void CallElevator(int nowFloor);//, int toFloor);
	void AddPeople(People addedPeople);
};

#endif