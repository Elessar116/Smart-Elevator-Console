#include "stdafx.h"
#include "Elevator.h"
using namespace std;
Elevator::Elevator() :currentFloor(1), currentPeople(0), totalOpTime(0),isFull(false), isWorking(false)
{
}
Elevator::~Elevator()
{
}
void Elevator::MoveTo(int floor , int& time)
{

}
void Elevator::PeopleEnter(People people)
{
	if (currentPeople >= capacity)
	{
		cout << "error: elevator is full" << endl;
	}
	else
	{
		inPeoples.push_back(people);
		currentPeople += 1;
		if (find(stopList.begin(), stopList.end(), people.GetToFloor()) == stopList.end())
		{
			stopList.push_back(people.GetToFloor());
		}
		if (currentPeople == capacity)
		{
			isFull = true;
		}
		else
		{
			isFull = false;
		}
	}
}
bool Elevator::IsFull()const
{
	return isFull;
}