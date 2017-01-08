#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "People.h"
#include <vector>
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
	//const int capacity = CAPACITY;
	int totalOpTime;
	vector<int> stopList;
	vector<People> inPeoples;
	bool isFull;
	bool isWorking;
	bool isGoUp;
public:
	Elevator();
	~Elevator();
	//void MoveUp();
	//void MoveDown();
	void MoveTo(int floor, int& time);
	void CallElevator(int floor);//, int toFloor);
	void PeopleEnter(People people);
	void UpdateStopList(vector<int>);
	void UpdateStopList(int);
	bool IsFull()const;
	bool IsWorking()const;
	bool IsGoUp()const;
	void SetToWork();
	void SetToRest();
	void SetToUp();
	void SetToDown();
	int GetCurrentFloor()const;
	void ShowStopList()const;
	void Work(int&);

};

#endif