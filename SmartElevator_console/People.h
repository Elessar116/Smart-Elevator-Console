#ifndef PEOPLE_H
#define PEOPLE_H

class People
{
private:
	bool isInBuilding;
	int currentFloor;
	int toFloor;
	int waitElevTime;
	int inElevTime;
public:
	People();
	~People();
};

#endif