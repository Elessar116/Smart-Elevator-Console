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
	bool isFull;
	bool isWorking;
public:
	Elevator();
	~Elevator();
	//void MoveUp();
	//void MoveDown();
	void MoveTo(int floor, int& time);
	void CallElevator(int floor);//, int toFloor);
	void PeopleEnter(People people);
	bool IsFull();
	int GetCurrentFloor()const;

};

#endif