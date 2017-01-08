#include "stdafx.h"
#include "Elevator.h"
#include <algorithm>
using namespace std;
Elevator::Elevator() :currentFloor(1), currentPeople(0), totalOpTime(0), isFull(false), isWorking(false), isGoUp(false)
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
	if (currentPeople >= CAPACITY)
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
		if (currentPeople == CAPACITY)
		{
			isFull = true;
		}
		else
		{
			isFull = false;
		}
	}
}
void Elevator::UpdateStopList(vector<int> stops)
{
	for (const int& stop : stops)
	{
		if (find(stopList.begin(), stopList.end(), stop) == stopList.end())
		{
			stopList.push_back(stop);
		}
	}
	//cout << endl;
}
void Elevator::UpdateStopList(int stop)
{	
	if (find(stopList.begin(), stopList.end(), stop) == stopList.end())
	{
		stopList.push_back(stop);
	}	
}
bool Elevator::IsFull()const
{
	return isFull;
}
bool Elevator::IsWorking()const
{
	return isWorking;
}
bool Elevator::IsGoUp()const
{
	return isGoUp;
}
void Elevator::SetToWork()
{
	isWorking = true;
}
void Elevator::SetToRest()
{
	isWorking = false;
}
void Elevator::SetToUp()
{
	isGoUp = true;
}
void Elevator::SetToDown()
{
	isGoUp = false;
}
int Elevator::GetCurrentFloor()const
{
	return currentFloor;
}
void Elevator::ShowStopList()const
{
	for_each(stopList.begin(), stopList.end(), [](int x){cout << "stop list: " << x << " "; });
	cout << endl;
}
void Elevator::Work(int& time)
{
	if (find(stopList.begin(), stopList.end(), currentFloor) != stopList.end())//is at destination
	{
		time += 3;//open door
		stopList.erase(remove(stopList.begin(), stopList.end(), currentFloor));
	}
	else
	{
		if (isGoUp)
		{
			
			int min = *min_element(stopList.begin(), stopList.end());
			time += ((min - currentFloor) * 3);
			totalOpTime += time;
			stopList.erase(remove(stopList.begin(), stopList.end(), min));
		}
		else
		{
			int max = *max_element(stopList.begin(), stopList.end());
			time += ((currentFloor - max) * 3);
			stopList.erase(remove(stopList.begin(), stopList.end(), max));
		}
	}
}