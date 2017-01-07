#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "People.h"
using namespace std;
const int  CAPACITY = 12;
const int TRAVEL_TIME = 3;
const int OPEN_TIME = 3;
const int CLOSE_TIME = 3;
class Elevator
{
private:
	int currentFloor;
	int currentPeople;
	const int capacity = CAPACITY;
	int totalOpTime;
	vector<int> stopList;
	vector<People> inPeoples;
	bool isWorking;
public:
	Elevator();
	~Elevator();
	//void MoveUp();
	//void MoveDown();
	void MoveTo(int floor);
	void CallElevator(int nowFloor);//, int toFloor);
	void AddPeople(People addedPeople);
	bool IsFull();
	int GetCurrentFloor()const;

};

#endif