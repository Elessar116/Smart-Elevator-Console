#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <vector>
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
	bool isWorking;
public:
	Elevator();
	~Elevator();
	void MoveUp();
	void MoveDown();
	void MoveTo(int floor);
	void CallElevator(int nowFloor, int toFloor);
};

#endif